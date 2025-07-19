#include <bitset>
#include <iostream>
#include <array>
#include <fstream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <Eigen/Dense>

std::mutex mtx;

using Matrix128 = Eigen::Matrix<unsigned long, 128, 128>;

// Function to XOR two 64-bit bitsets
std::bitset<128> XORing(const std::bitset<128>& input1, const std::bitset<128>& input2) {
    return input1 ^ input2;
}

void swapBits(std::bitset<128>& bs) {
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
std::bitset<128> evolution_CA(const std::bitset<128>& input, int time_steps, const int rule_vector[128]) {
    std::bitset<128> current_state = input;
    std::bitset<128> next_state;

    for (int step = 0; step < time_steps; ++step) {
        for (size_t i = 0; i < current_state.size(); ++i) {
            std::bitset<3> neighborhood;

            // Determine Left_N, Middle, Right_N based on null boundary condition
            if (i > 0) {
                neighborhood[2] = current_state.test(i - 1); // Left neighbor
            } else {
                neighborhood[2] = 0; // Null boundary condition for left neighbor
            }

            neighborhood[1] = current_state.test(i); // Middle cell itself

            if (i < current_state.size() - 1) {
                neighborhood[0] = current_state.test(i + 1); // Right neighbor
            } else {
                neighborhood[0] = 0; // Null boundary condition for right neighbor
            }

            // Apply the rule to get the new state of the current cell
            next_state[i] = apply_rule(neighborhood, rule_vector[i]);

            // Debugging output
            // std::cout << "Step: " << step << " Cell: " << i << " Neighborhood: " << neighborhood 
        }
        current_state = next_state; // Update the state for the next time step
    }
    swapBits(current_state);
    return current_state;
}

// Function to multiply a state vector by the Rule 90 matrix
std::bitset<128> multiply_by_rule90_matrix(const std::bitset<128>& state, const Matrix128& matrix) {
    Eigen::Matrix<unsigned long, 128, 1> state_vector;
    for (size_t i = 0; i < 128; ++i) {
        state_vector(i, 0) = state[i];
    }

    Eigen::Matrix<unsigned long, 128, 1> new_state_vector = matrix * state_vector;

    std::bitset<128> new_state;
    for (size_t i = 0; i < 128; ++i) {
        new_state[i] = new_state_vector(i, 0) % 2;
    }

    return new_state;
}

// Function to create the Rule 90 matrix
Matrix128 create_rule90_matrix() {
    Matrix128 matrix = Matrix128::Zero();

    for (size_t i = 0; i < 128; ++i) {
        if (i > 0) {
            matrix(i, i - 1) = 1;
        }
        if (i < 127) {
            matrix(i, i + 1) = 1;
        }
    }

    return matrix;
}

void write_to_bin_file(const std::bitset<128>& encrypted_message, const std::string& filename) {
    std::ofstream outfile(filename, std::ios::binary | std::ios::app); // Open file in binary append mode
    if (!outfile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    // Convert each 8-bit chunk into a byte and write to the binary file
    for (size_t i = 0; i < encrypted_message.size(); i += 8) {
        std::bitset<8> byte;
        for (size_t j = 0; j < 8; ++j) {
            byte[j] = encrypted_message[i + j];
        }
        unsigned char byte_value = static_cast<unsigned char>(byte.to_ulong());
        outfile.write(reinterpret_cast<const char*>(&byte_value), sizeof(byte_value));
    }

    outfile.close();
}

void process_chunk(std::bitset<128> input_bitset1, std::bitset<128> input_bitset2, const Matrix128& rule90_matrix, int thread_id, const std::string& filename) {
    std::bitset<128> help;
    help = input_bitset1;

    for (int i = 0; i < 67200000 / 4 ; ++i) {
        std::bitset<128> bitset1(help);
        std::bitset<128> bitset2(input_bitset2);
        std::bitset<128> xor_result = XORing(bitset1, bitset2);
        help = multiply_by_rule90_matrix(input_bitset1, rule90_matrix);
        input_bitset1 = help;

        
        int rule_vector[128] = {
            5, 105, 
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 105, 90, 90, 90,
            105, 90, 90, 90, 149, 80
        };

        int time_steps = 128;
        swapBits(xor_result);
        std::bitset<128> evolved_result = evolution_CA(xor_result, time_steps, rule_vector);
        int rule_vector_linear[128] = {
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
            153, 153, 153, 153, 153, 153, 153, 153,
        };

        int time_steps_linear = 128;
        swapBits(evolved_result);
        std::bitset<128> evolved_final_result = evolution_CA(evolved_result, time_steps_linear, rule_vector_linear);

        std::bitset<128> encrypted_message;
        encrypted_message=evolved_final_result;

        mtx.lock();
        write_to_bin_file(encrypted_message, filename);
        mtx.unlock();

        input_bitset2 = evolved_final_result;
    }
}

void AllWork() {
    std::bitset<128> input_bitset1_thread0("00000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000");
    std::bitset<128> input_bitset1_thread1("00000000000000010000000000000000000000000000000100000000000000000000000000000001000000000000000000000000000000010000000000000000");
    std::bitset<128> input_bitset1_thread2("00000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000001");
    std::bitset<128> input_bitset1_thread3("00000001000000000000000100000000000000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000");
    Matrix128 rule90_matrix = create_rule90_matrix();

    // Calculate the k-th evolution of initial_state
    int k = 16800000; // Example: compute 10th evolution
    std::bitset<128> input_bitset1_thread1 = input_bitset1_thread0;
    for (int i = 0; i < k; ++i) {
        input_bitset1_thread1 = multiply_by_rule90_matrix(input_bitset1_thread1, rule90_matrix);
    }
    std::cout<<input_bitset1_thread1<<std::endl;

    int l = 16800000; // Example: compute 10th evolution
    std::bitset<128> input_bitset1_thread2 = input_bitset1_thread1;
    for (int i = 0; i < l; ++i) {
        input_bitset1_thread2 = multiply_by_rule90_matrix(input_bitset1_thread2, rule90_matrix);
    }

    int m = 16800000; // Example: compute 10th evolution
    std::bitset<128> input_bitset1_thread3 = input_bitset1_thread2;
    for (int i = 0; i < m; ++i) {
        input_bitset1_thread3 = multiply_by_rule90_matrix(input_bitset1_thread3, rule90_matrix);
    }

    // Four IVs
    std::bitset<128> input_bitset2_thread0("10001000010101000111000010100000101001011000011100110011101100110011010011101101111001111101010011000111000001001011100011011100");
    std::bitset<128> input_bitset2_thread1("11001101001011001110010110011101110111010110010011000110011001011110110101111010001001001000110000110010111101110010001011011111");
    std::bitset<128> input_bitset2_thread2("01010001100101110100111100001000101001000010010001111101011011110100000101111101101111100101010100110101100100000111000001011001");
    std::bitset<128> input_bitset2_thread3("11000000111110111101011011110010011110110111000100111011100101011000001111011010000000011100010110000101100111000010000111010111");


    std::vector<std::thread> threads;
    threads.emplace_back(process_chunk, std::ref(input_bitset1_thread0), std::ref(input_bitset2_thread0), std::ref(rule90_matrix), 1, "new1_thread_1_Rule_vector_1_.bin");
    threads.emplace_back(process_chunk, std::ref(input_bitset1_thread1), std::ref(input_bitset2_thread1), std::ref(rule90_matrix), 2, "new1_thread_2_Rule_vector_1_.bin");
    threads.emplace_back(process_chunk, std::ref(input_bitset1_thread2), std::ref(input_bitset2_thread2), std::ref(rule90_matrix), 3, "new1_thread_3_Rule_vector_1_.bin");
    threads.emplace_back(process_chunk, std::ref(input_bitset1_thread3), std::ref(input_bitset2_thread3), std::ref(rule90_matrix), 4, "new1_thread_4_Rule_vector_1_.bin");

    for (auto& thread : threads) {
        thread.join();
    }


}

int main() {
    AllWork();
    std::bitset<128> IV1("10001000010101000111000010100000101001011000011100110011101100110011010011101101111001111101010011000111000001001011100011011100");
    std::bitset<128> IV2("11001101001011001110010110011101110111010110010011000110011001011110110101111010001001001000110000110010111101110010001011011111");
    std::bitset<128> IV3("01010001100101110100111100001000101001000010010001111101011011110100000101111101101111100101010100110101100100000111000001011001");
    std::bitset<128> IV4("11000000111110111101011011110010011110110111000100111011100101011000001111011010000000011100010110000101100111000010000111010111");
    write_to_bin_file(IV1,"new1_thread_1_Rule_vector_1_.bin");
    write_to_bin_file(IV2,"new1_thread_2_Rule_vector_1_.bin");
    write_to_bin_file(IV3,"new1_thread_3_Rule_vector_1_.bin");
    write_to_bin_file(IV4,"new1_thread_4_Rule_vector_1_.bin");
    return 0;
}

