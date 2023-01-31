N = int(input())

arr = list(map(int, input().split(' ')))

if N == 1:
  print(0)
  exit()

answer = 0

for i in range(0, N):
  count = 0

  for j in range(0, N):
    if (j == i):
      continue
    
    
    incline = (arr[j]-arr[i]) / (j-i) 
    offset = arr[i] - (incline * i)
    
    visible = True
    if i < j:
      for k in range(i+1, j):
        if k * incline + offset <= arr[k]:
          visible = False;
          break;
    else:
      for k in range(j+1, i):
        if k * incline + offset <= arr[k]:
          visible = False;
          break;

    if visible:
      count += 1
  
  if count > answer:
    answer = count

print(answer)