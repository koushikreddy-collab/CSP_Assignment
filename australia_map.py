states = ['WA','NT','SA','QLD','NSW','VIC','T']

neighbors = {
    'WA': ['NT','SA'],
    'NT': ['WA','SA','QLD'],
    'SA': ['WA','NT','QLD','NSW','VIC'],
    'QLD': ['NT','SA','NSW'],
    'NSW': ['QLD','SA','VIC'],
    'VIC': ['SA','NSW'],
    'T': []
}

colors = ['Red','Green','Blue']

def is_valid(state, color, assignment):
    for neighbor in neighbors[state]:
        if neighbor in assignment and assignment[neighbor] == color:
            return False
    return True

def backtrack(assignment):
    if len(assignment) == len(states):
        return assignment

    for state in states:
        if state not in assignment:
            for color in colors:
                if is_valid(state, color, assignment):
                    assignment[state] = color
                    result = backtrack(assignment)
                    if result:
                        return result
                    del assignment[state]
            return None

solution = backtrack({})
print("Australia Map Coloring:", solution)
