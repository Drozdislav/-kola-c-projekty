
# Task 1: Build a data frame ----------------------------------------------

Party <- c("Sinn Féin", "DUP", "Alliance", "UUP", "SDLP")
Seats <- c(27,25,17,9,8)

assembly <- data.frame(Party, Seats)

assembly <- rbind(assembly, data.frame(
  Party = c("Independents", "People Before Profit", "TUV"),
  Seats = c(2,1,1)
  )
)

# Task 2: Add a variable --------------------------------------------------

assembly$Designation <- c("Nationalist", "Unionist", "Other", "Unionist", "Nationalist", "Unionist", "Other", "Unionist")

# Task 3: Central Tendency ------------------------------------------------

sum(assembly$Seats)

#i thought the mean will be larger because i know that the last three values are 2,1,1 which ofsets the median?
mean(assembly$Seats)
median(assembly$Seats)

#neither of them describe it well i think

table(Designation)
#the mode is Unionist

# Task 4: Graphs ----------------------------------------------------------

barplot(assembly$Seats, names.arg = assembly$Party, main = "Election Results")
abline(h = mean(assembly$Seats), col = "red")
abline(h = median(assembly$Seats), col = "green")
#the difference between mean and median, it shows that the seats are dominated with a few values that are quite bigger than the others; inequality in the distribution in votes

# Task 5: Logical vectors and selecting -----------------------------------

assembly$Seats

big_party <- 10 <= assembly$Seats
sum(big_party) #because true is 1 and false is 0

assembly$Party[3]

# Task 6: Fix the code ----------------------------------------------------

mean(assembly$Seats) 
#it did not work because seats does not exist only Seats exist, capital / small letters matter

assembly_combined <- data.frame(assembly$Party, assembly$Seats)
#to be honest I do not really understand what was this supposed to do but if it was to create a new data frame then i fixed it

decades <- seq(1990, 2020, by = 10)
#there was a minus before the 10 so logically by substracting it would never reach 2020


barplot(assembly$Seats, names.arg = assembly$Party)
#the p was small so it did not show names because it was trying to see another vector which is empty


# Task 7: Logical vectors and coercion ------------------------------------

#i think it would combine in one character vector, automatically converting the numerical to characters (numbers can be characters but characters cannot be numbers)
test <- c(assembly$Party, assembly$Seats)
class(test)
