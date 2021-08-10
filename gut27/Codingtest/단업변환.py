def solution(begin, target, words):
    global result
    result = 1e9
    length_b = len(begin)
    if target not in words:
        return 0
    
    visited = [False] * len(words)
    def dfs(begin,visited,count):
        global result
        if begin == target:
            return count
        if count == len(words):
            return
        for i in range(len(words)):
            c = 0
            if visited[i] == True:
                continue
            for j in range(length_b):
                if begin[j] == words[i][j]:
                    c+=1
            if c == (length_b-1):
                visited[i] = True
                a = dfs(words[i],visited,count+1)
                visited[i] = False
                if a:
                    result = min(result,a)
    dfs(begin,visited,0)
    return result
