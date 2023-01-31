
def solve(N):
  dp = [float('inf') for i in range(0, int(N)+1)]

  if len(N) == 1:
    return -1

  for i in range(0,10):
    dp[i] = -1;

  for i in range(10, int(N)+1):
    num_str = str(i)
    partial_num = set()

    for j in range(0, len(num_str)):
      for k in range(j, len(num_str)):
        partial_int_num = int(num_str[j:k+1])
        if (partial_int_num != i and partial_int_num != 0):
          partial_num.add(partial_int_num)

    for j in partial_num:
      if dp[i-j] == -1:
        dp[i] = min(dp[i], j)
    
    if dp[i] == float('inf'):
      dp[i] = -1
  
  return dp[int(N)];

print(solve(input()))
