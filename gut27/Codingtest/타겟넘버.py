def dfs(start,number, flag,numbers,target):
    global count
    
    if start == len(numbers):
        if number == target:
            count += 1
        return
    if flag == 'plus':
        number = number + numbers[start]
    else:
        number = number - numbers[start]
    
    
    dfs(start+1, number,'plus',numbers,target)
    dfs(start+1, number,'minus',numbers,target)

        
def solution(numbers, target):
    global count 
    answer = 0
    count = 0
    
    dfs(0,0,'minus',numbers,target)
    dfs(0,0,'plus',numbers,target)

    answer = count//2
    return answer
