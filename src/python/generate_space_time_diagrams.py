"""Space time Diagram for 8 cell Rule vectors"""

import random
import os
import numpy as np
import matplotlib.pyplot as plt
from google.colab import files

def plot_ca_space_time_diagram(n, rule_vector, time_steps, initial_state=None):
    """
    Plot the space-time diagram for a nonlinear, non-uniform cellular automaton.

    Parameters:
    n (int): Length of the cellular automaton.
    rule_vector (list of int): List of rules for each cell.
    time_steps (int): Number of time steps to simulate.
    initial_state (list of int, optional): Initial state of the CA. If None, a random state is used.
    """
    # Check if rule_vector length matches n
    if len(rule_vector) != n:
        raise ValueError("Length of rule_vector must be equal to n")

    # Convert rules to binary and store them
    rules = [np.array(list(np.binary_repr(rule, width=8)), dtype=int) for rule in rule_vector]

    # Initialize state
    if initial_state is None:
        initial_state = np.random.randint(2, size=n)
    else:
        if len(initial_state) != n:
            raise ValueError("Length of initial_state must be equal to n")
        initial_state = np.array(initial_state)

    # Create a matrix to hold the states over time
    ca_matrix = np.zeros((time_steps, n), dtype=int)

    ca_matrix[0] = initial_state

    # Function to get the new state based on the rule
    def get_new_state(left, center, right, rule):
        binary_number = str(left) + str(center) + str(right)
        decimal_number = int(binary_number, 2)
        ret = rule[(7 - decimal_number)]
        return ret

    # Update the CA over time
    for t in range(1, time_steps):
        for i in range(0, n):
            if i == 0:
                left = 0
                center = ca_matrix[t - 1, i]
                right = ca_matrix[t - 1, (i + 1)]
            elif i == n - 1:
                left = ca_matrix[t - 1, (i - 1)]
                center = ca_matrix[t - 1, i]
                right = 0
            else:
                left = ca_matrix[t - 1, (i - 1)]
                center = ca_matrix[t - 1, i]
                right = ca_matrix[t - 1, i + 1]

            ca_matrix[t, i] = get_new_state(left, center, right, rules[i])

    # Plot the space-time diagram
    fig, ax = plt.subplots(figsize=(10, 10))
    ax.imshow(ca_matrix, cmap='Greys', interpolation='none')
    ax.set_title(f'Space-Time Diagram for Rule Vector: {rule_vector}')
    ax.set_xlabel('Cells')
    ax.set_ylabel('Time Steps')
    ax.set_xticks(range(n))
    ax.set_yticks(range(time_steps))
    ax.set_xticklabels(range(1, n + 1))
    ax.set_yticklabels(range(1, time_steps + 1))

    # Ensure the folder exists
    folder = 'Cellular_Automata_Space_time_diagram_8bit/'
    if not os.path.exists(folder):
        os.makedirs(folder)

    # Save the plot to the folder
    filename = '-'.join(map(str, rule_vector)) + '.png'
    save_path = os.path.join(folder, filename)
    plt.savefig(save_path)

    # Display the plot
    plt.show()

    # Close the plot to free memory
    plt.close()

    return save_path

# Example usage
n = 8
rule_vectors = [[9, 169, 90, 169, 105, 150, 165, 80],[10, 105, 106, 150, 90, 150, 169, 5],[6, 169, 105, 90, 150, 86, 150, 65],[9, 86, 150, 105, 166, 165, 90, 5],[9, 86, 150, 105, 166, 90, 165, 80],[5, 105, 149, 90, 165, 90, 150, 80]]
initial_states = [[0, 0, 0, 1, 1, 1, 1, 1],[0, 0, 0, 1, 1, 1, 1, 1],[0, 0, 0, 1, 1, 1, 1, 1],[0, 0, 0, 1, 1, 1, 1, 1],[0, 0, 0, 1, 1, 1, 1, 1],[0, 0, 1, 0, 1, 1, 1, 0]]

time_steps = 200

# Store paths of saved files
saved_files = []

# Loop through rule vectors and initial states
for rule_vector, initial_state in zip(rule_vectors, initial_states):
    save_path = plot_ca_space_time_diagram(n, rule_vector, time_steps, initial_state)
    saved_files.append(save_path)

# Download all files
for file in saved_files:
    files.download(file)
