import random

def generate_input():
    num_vertices = random.randint(100, 200)
    num_edges = random.randint(200, 1000)
    
    edges = []
    for _ in range(num_edges):
        source = random.randint(1, num_vertices)
        destination = random.randint(1, num_vertices)
        weight = random.randint(1, 100)
        edges.append((source, destination, weight))
    
    input_data = f"{num_vertices} {num_edges}\n"
    for edge in edges:
        input_data += f"{edge[0]} {edge[1]} {edge[2]}\n"
    
    return input_data

def save_input_to_file(input_data, filename):
    with open(filename, "w") as file:
        file.write(input_data)

# Gera a entrada aleatória
input_data = generate_input()

# Salva a entrada em um arquivo .mtx
filename = "input20.mtx"
save_input_to_file(input_data, filename)

print(f"A entrada foi gerada e salva no arquivo {filename}.")
