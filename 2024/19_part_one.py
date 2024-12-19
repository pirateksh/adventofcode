possible = set()
not_possible = set()

def is_design_possible(design, patterns):
    if design in possible:
        return True
    if design in not_possible:
        return False
    if design == "":
        return False
    if design in patterns:
        possible.add(design)
        return True
    
    is_possible = False
    
    for i in range(1, len(design)):
        start = design[:i]
        end = design[i:]
        is_start_possible = is_design_possible(start, patterns)
        if is_start_possible:
            is_end_possible = is_design_possible(end, patterns)
            is_possible = is_start_possible and is_end_possible
        if is_possible:
            break
    
    if is_possible:
        possible.add(design)
    else:
        not_possible.add(design)
        
    return is_possible


patterns = str(input()).split(",")
patterns = {pattern.strip() for pattern in patterns}
input() # For empty line
i = 0
designs = []
while(i < 400):
    designs.append(input())
    i += 1

count = 0
for design in designs:
    if is_design_possible(design, patterns):
        count += 1
        
        
print("Answer is:", count)
