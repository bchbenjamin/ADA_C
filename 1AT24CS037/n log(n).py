import matplotlib.pyplot as plt
import numpy as np

# Define the range for n (e.g., from 1 to 100)
n = np.linspace(1, 100, 400) 

# Calculate n * log(n). Using base 2 is standard for CS algorithms.
y = n * np.log2(n)

# Create the plot
plt.figure(figsize=(8, 5))
plt.plot(n, y, label='n log(n)', color='blue', linewidth=2)

# Add labels and title
plt.title('Visualization of n log(n) Growth')
plt.xlabel('Input Size (n)')
plt.ylabel('Operations')
plt.grid(True)
plt.legend()

# Display the graph
plt.show()
