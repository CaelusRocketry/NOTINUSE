import math
if __name__ == "__main__":
    runrcs()
def runrcs():
    while True:
        stopspinning()
        keepstraight()
        
def stopspinning(): #Assumes CW is positive on gyroscope
    while True:
        if(abs(gyroz)<1.5):     
            break
        while(gyroz>0):
            bob = gyroz*5
            if(bob>1024):
                bob = 1024
            writeprop3(bob) #Change to writeprop1 if CCW
            writeprop2(bob) #Change to writeprop4 if CCW
        writeprop1(0)
        writeprop4(0)
        while(gyroz<0):
            bob = -1*gyroz*5
            if(-1*bob>1024):
                bob = 1024
            writeprop1(bob) #Change to writeprop3 if CCW
            writeprop4(bob) #Change to writeprop2 if CCW
        writeprop3(0)
        writeprop2(0)
        
def keepstraight():
    while True:
        


##     /\
##    /  \ 
##   /    \
## 1/      \2
## /        \ 
##/          \
##|          |
##|    EDF   |
##|          |
##\          /
## \        /
## 3\      /4
##   \    /
##    \  /
##     \/
## I'M TESTING GITHUB NOTIFICATIONS ON SLACK -JASON 2/2/19