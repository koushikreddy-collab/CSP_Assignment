districts = ['Adilabad','Nirmal','Nizamabad','Kamareddy','Karimnagar','Warangal']

neighbors = {
    'Adilabad': ['Nirmal'],
    'Nirmal': ['Adilabad','Nizamabad'],
    'Nizamabad': ['Nirmal','Kamareddy'],
    'Kamareddy': ['Nizamabad','Karimnagar'],
    'Karimnagar': ['Kamareddy','Warangal'],
    'Warangal': ['Karimnagar']
}

colors = ['Red','Green','Blue','Yellow']

def is_valid(district, color, assignment):
    for neighbor in neighbors[district]:
        if neighbor in assignment and assignment[neighbor] == color:
            return False
    return True

def backtrack(assignment):
    if len(assignment) == len(districts):
        return assignment

    for d in districts:
        if d not in assignment:
            for color in colors:
                if is_valid(d, color, assignment):
                    assignment[d] = color
                    result = backtrack(assignment)
                    if result:
                        return result
                    del assignment[d]
            return None

solution = backtrack({})
print("Telangana Coloring:", solution)
