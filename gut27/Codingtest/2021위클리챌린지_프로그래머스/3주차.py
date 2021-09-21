def search(block,i,j)

def road_block(block):
    block_lists = []
    
    for i in range(len(block)):
        for j in range(len(block)):
            if block[i][j] == 1:
                block_list = search(block,i,j)
                x,y = block_list[0]
                if x != 0:
                    for z in range(len(block_list)):
                        block_list[z] = (block_list[z][0]-x,block_list[z][1])
                if y != 0:
                    for z in range(len(block_list)):
                        block_list[z] = (block_list[z][0],block_list[z][1]-y)
                block_lists.append(list(block_list))
    return block_lists
def solution(game_board, table):
    answer = 0
    
    gm_blocks = road_block(game_board)
    tb_blocks = road_block(table)
    gm_truth = [False]*len(gm blocks)
    # check
    for tb_block in tb_blocks:
        for i in range(len(gm_blocks)):
            if tb_block == gm blocks[i] and gm_truth[i] == False:
                answer += 1
                gm_truth[i] = True
                
    return answer
