import random
import time

def foo(x, y, z):
    return 2*x**3 + 7*y**2 + 21*z - 9  
#this is the eequation, but it could be any type of equation. I chose one with three variables, but it could have much more or less.

def fitness(x, y, z):
    ans = foo(x, y, z)
    if ans == 0:
        return 100000
    else:
        return abs(1/ans) 
#my fitness function solves the eequation and if the value is exactly 0, then it gives a very high number, i.e. 100000.
#if not, I geet the recriprocal of the number, this because if it is very colse to 0, like 0.00001, I would get 10000, which is pretty high.

#generate solutions
solutions = []
for s in range(1000):
    solutions.append( (random.uniform(0, 10000), random.uniform(0, 10000), random.uniform(0, 10000)) )


start = time.time()

for i in range(10000):
    rankedsolutions = []  #I create the list for all the solutions after being ranked.
    for s in solutions:
        rankedsolutions.append( (fitness(s[0], s[1], s[2]), s) ) #I append the values to the previous list, plus their fitness value.
    rankedsolutions.sort()
    rankedsolutions.reverse() #here, I am ranking the solutions and sorting from the best to the worst
    
    print(f"=== Gen {i} best solutions ===")
    print(rankedsolutions[0])

    if rankedsolutions[0][0] > 50000:
        break  #I don't want the code to keep going if I already have a sufficiently good answer

    bestsolutions = rankedsolutions[:50] #I just want to process the best 100 solutions, all the others are bad. I changed it to 50, and I get better values.

    elements = []
    for s in bestsolutions:
        elements.append(s[1][0])
        elements.append(s[1][1])
        elements.append(s[1][2])
    
    newGen = []
    for _ in range(1000):
        e1 = random.choice(elements) * random.uniform(0.99, 1.01)
        e2 = random.choice(elements) * random.uniform(0.99, 1.01)
        e3 = random.choice(elements) * random.uniform(0.99, 1.01) 
        newGen.append( (e1, e2, e3) )
#1:mutation has 5 options; multiplying by either 0.98, 0.99, 1.00, 1.01, 1.02. Then I changed it to only 0.99 or stay the same; it did't work.
#the third time i changed it to random between 0.99 and 1.01
    
    solutions = newGen
    elements.sort()
    elements.reverse()
    
#print(f"the best solution is:\n=== {bestsolutions[0]} ===")
end = time.time()
print(f"time: {end - start}s") #I just wanted to know how many seconds my computer took to get the answer

#window = tk.Tk()
#window.geometry("100*50")
#window.mainloop()