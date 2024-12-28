

def MathChallenge(str):
    # Split the equation by equals sign to get left and right sides
    left, right = str.split('=')
    left = left.strip()
    right = right.strip()
    
    # Find the position of x
    if 'x' in left:
        expression_side = left
        result = float(right)
    else:
        expression_side = right
        result = float(left)
    
    # Split the expression side into components
    parts = expression_side.replace(' ', '').replace('x', '')
    
    # Find the operator
    operator = None
    for op in ['+', '-', '*', '/']:
        if op in parts:
            operator = op
            break
    
    # Split numbers based on operator
    nums = parts.split(operator)
    nums = [num for num in nums if num]  # Remove empty strings
    
    # Get the position of x in the expression
    x_pos = expression_side.find('x')
    
    # Solve for x based on operator and position
    if operator == '+':
        if x_pos == 0:  # x + b = c
            x = result - float(nums[0])
        else:  # a + x = c
            x = result - float(nums[0])
    elif operator == '-':
        if x_pos == 0:  # x - b = c
            x = result + float(nums[0])
        else:  # a - x = c
            x = float(nums[0]) - result
    elif operator == '*':
        if x_pos == 0:  # x * b = c
            x = result / float(nums[0])
        else:  # a * x = c
            x = result / float(nums[0])
    elif operator == '/':
        if x_pos == 0:  # x / b = c
            x = result * float(nums[0])
        else:  # a / x = c
            x = float(nums[0]) / result
            
    # Return the integer result
    return int(x)