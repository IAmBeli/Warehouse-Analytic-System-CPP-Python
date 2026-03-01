import matplotlib.pyplot as plt
import numpy as np
names = []
total_value = []
try:
    with open(r"c:\works\dataprices.txt", "r") as f:
        for line in f:
            parts = line.split()
            if len(parts) >= 3:
                names.append(parts[0])
                total_value.append(float(parts[1]) * float(parts[2]))
    plt.figure(figsize=(11, 8))
    colors = plt.cm.plasma(np.linspace(0, 0.8, len(names)))
    bars = plt.barh(names, total_value, color=colors)
    plt.xlabel("Total sum ($)")
    plt.ylabel("Part's name")
    plt.grid(axis='x', linestyle = '--', alpha = 0.7)
    for i, v in enumerate(total_value):
        plt.text(v + 3, i, str(int(v)), color="black", va="center", fontweight="bold")
    plt.title("Warehouse's supplies analysis")
    plt.savefig("warehouse_report.png")
    print("Report is updated and saved as warehouse_report.png")
    plt.show()
except FileNotFoundError:
    print("Error, file was not found!")
except Exception as e:
    print(f"Error {e}")