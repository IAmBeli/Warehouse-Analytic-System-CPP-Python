import matplotlib.pyplot as plt
import numpy as np
names = []
id = []
quantities = []
total_value = []
try:
    with open(r"c:\works\dataprices.txt", "r") as f:
        for line in f:
            parts = line.split()
            if len(parts) >= 4:
                names.append(parts[0])
                id.append(float(parts[1]))
                total_value.append(float(parts[2]) * float(parts[3]))
                quantities.append(int(parts[3]))
    colors = []
    for q in quantities:
        if q < 5:
            colors.append('#ff4d4d')
        elif q < 10:
            colors.append('#ffcc00')
        else:
            colors.append('#2eb82e')
    plt.figure(figsize=(12, 7))
    bars = plt.barh(names, total_value, color=colors, edgecolor='black', alpha=0.8)
    plt.xlabel("Total value on stock($)", fontsize=12)
    plt.title("Warehouse inventory status (red = low stock!)", fontsize=14, fontweight='bold')
    plt.grid(axis='x', linestyle='--', alpha=0.6)
    for i, (v, q) in enumerate(zip(total_value, quantities)):
        plt.text(v + 5, i, f"${int(v)} ({q} in stock)", va='center', fontweight='bold')
    plt.tight_layout()
    plt.savefig("warehouse_report.png")
    print("Report generated: warehouse_report.png")
    plt.show()
except FileNotFoundError:
    print("Error: dataprices.txt not found!")
except Exception as e:
    print(f"An error occured: {e}")