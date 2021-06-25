def change(song): 
    song = song.replace('C#', 'c')
    song = song.replace('D#', 'd')
    song = song.replace('F#', 'f')
    song = song.replace('G#', 'g')
    song = song.replace('A#', 'a')    
    return song

def solution(m, musicinfos):
    answer = ''
    arr = []
    num = 0
    m = change(m)
    for mus in musicinfos:
        s,e,t,i = mus.split(',')
        s = s.split(':')
        e = e.split(':')
        time = (int(e[0])*60+int(e[1])) - (int(s[0])*60+int(s[1]))
        i = change(i)
        
        if len(i) > time :
            song = i[0:time]
        else:
            q,r = divmod(time,len(i))
            song = i * q + i[0:r]
        arr.append((t,song,time,num,len(i)))
        num+=1
    length = len(m)
    arr.sort(key=lambda x:(-x[2],x[3]))

    for ar in arr:
        t,i,time,num,i_l = ar
        if m in i:
            return t
    if len(answer) == 0:
        answer='(None)'
                    
    return answer
