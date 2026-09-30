satisfaction <- c(5,8,2,6,9,4,7,3)
class(satisfaction)
length(satisfaction)

respID <- c("R1","R2","R3","R4","R5","R6","R7","R8")
names(satisfaction) <- respID

satisfaction2 <- c(6, 1, 8, 5,-7)
respID2 <- c("R8","R9" ,"R10", "R11", "R12")
names(satisfaction2) <- respID2
satisfactionALL <- c(satisfaction, satisfaction2)

satisfactionALL #prints all values
sign(satisfactionALL)

satisfactionALL <- abs(satisfactionALL) #rewrites all satisfationALL numbers to abs

satisfactionALL #prints all sat

sign(satisfactionALL) #prints vector value 