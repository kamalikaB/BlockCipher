// This C++ program simulates a 32-bit one-dimensional cellular automaton (CA) with spatially varying rules (e.g., Rule 90, 105). It starts with a single '1' in the center and applies a unique bit-reversal after each evolution step. The program tracks if the CA returns to its initial state (indicating periodicity) or evolves for up to 2 hours to study long-term behavior. A time-based limit was adopted because larger bit sizes (e.g., >24 bits) made exhaustive runs too time-consuming, ensuring computational feasibility while analyzing periodicity or patterns.
#include <bitset>
#include <chrono>
#include <iostream>

// Function to swap bits symmetrically in a bitset
void swapBits(std::bitset<32>& bs) {
    for (size_t i = 0; i < bs.size() / 2; ++i) {
        bool temp = bs.test(i);
        bs.set(i, bs.test(bs.size() - i - 1));
        bs.set(bs.size() - i - 1, temp);
    }
}

// Function to get the new state of a cell based on its neighborhood and rule
bool apply_rule(std::bitset<3> neighborhood, int rule) {
    std::bitset<8> rule_bits(rule);
    int index = static_cast<int>(neighborhood.to_ulong());
    return rule_bits[index];
}

// Function to evolve the cellular automaton
std::bitset<32> evolution_CA(const std::bitset<32>& input, const int rule_vector[32]) {
    std::bitset<32> current_state = input;
    std::bitset<32> next_state;

    for (size_t i = 0; i < current_state.size(); ++i) {
        std::bitset<3> neighborhood;

        // Determine Left_N, Middle, Right_N based on null boundary condition
        neighborhood[2] = (i > 0) ? current_state.test(i - 1) : 0; // Left neighbor
        neighborhood[1] = current_state.test(i);                   // Middle cell
        neighborhood[0] = (i < current_state.size() - 1) ? current_state.test(i + 1) : 0; // Right neighbor

        // Apply the rule to get the new state of the current cell
        next_state[i] = apply_rule(neighborhood, rule_vector[i]);
    }
    swapBits(next_state); // Swap bits as per your design
    return next_state;
}

int main() {
    std::bitset<32> initial_config;
    initial_config.set(16); // Setting the first bit to 1 for initial configuration

    int rule_vector[32] = {
        5, 105, 105, 90, 90, 90,105, 90, 90, 90,105, 90, 90, 90,105, 90, 90, 90,105, 90, 90, 90, 105, 90, 90, 90, 105, 90, 90, 90, 149, 80
    };

    std::bitset<32> current_config = initial_config;
    int evolution_count = 0;

    // Mark the start time
    auto start_time = std::chrono::steady_clock::now();

    while (true) {
        // Evolve the CA configuration
        current_config = evolution_CA(current_config, rule_vector);
        evolution_count++;

        // Check if we've returned to the initial configuration
        if (current_config == initial_config) {
            std::cout << "Returned to initial configuration after " << evolution_count << " evolutions.\n";
            std::cout << "Final configuration: " << current_config << "\n";
            break;
        }

        // Check if 2 hours have passed
        auto current_time = std::chrono::steady_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::hours>(current_time - start_time);
        if (elapsed_time.count() >= 2) {
            std::cout << "Did not return to initial configuration after 2 hours.\n";
            std::cout << "Total evolutions in 2 hours: " << evolution_count << "\n";
            std::cout << "Final configuration: " << current_config << "\n";
            break;
        }
    }
    return 0;
}
