
# Week 1 - basic objects and assignment -----------------------------------

#you can create labels/sections with ctrl+shift+r, also 
  #above the console you can choose which section u want to go to
1+1
1*5
sqrt(8)
sign(0)
?sing #it shows what it means 


# Basic objects -----------------------------------------------------------


a <- 1
class(a)
b <- 2
c <- 3
a+b
d<- a+b
ceiling(sqrt(a+b))
floor(sqrt(a+b))
round(sqrt(a+b),2)

# character objects -------------------------------------------------------

artist <- "polana"
class(artist)
album <- "lidovky"


# vectors -----------------------------------------------------------------

vec_a <- c(1,2,3)
vec_b <- c(100,200,300)

class(vec_a)

vec_ab <- vec_a*100

vec_abcd <- c(vec_a, vec_b) #combining vectors

vec_abcd
