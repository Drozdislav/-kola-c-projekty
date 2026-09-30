# #week 2 - Dataframes and basic graphs -----------------------------------

a <- 3
a < 7
b <- a < 5

class(b)

c <- a > 5
a <- a 
e <- a==4


x1 <- c(3,7,4)
x2 <- c(8,5,1)
x3 <- x1<=x2

x4 <- 1:10
x5 <- 1.5:5

seq(from = 0, to = 22, by =2.5)
seqx <- seq(-77,89, by=pi)
seqx


?rep
xrep <- rep(3,2) #first is the number in hte repetiotion, second one is how many times it will be repeated
zrep <- rep(c(2,6,7), 4)



# coercion ----------------------------------------------------------------

vaary <- c("hello", 7, "kokot") #kdyz jsou values ruzny, vsechno je character!!!!
?rm #removes things from enviroment, rm(list = ls()) removes the entire enviroment



# Dataframe / dataset -----------------------------------------------------

empty <- data.frame() #creates empty data frame /set??
album <- c("rap", "gay rap", "pop")
artist <- c("Dollar Prync", "Hard Risa", "Taylor Swift")
music <- data.frame(album, artist)
str(music)

#adding observations
?rbind
music_new <- rbind(music, data.frame
  (
    album = c ("Rum", "Sodomy"),
    artist = c("The Pogues", "Fleetwood Mac")
  )
)

#Isolating or selecting variables
music_new$album
music_new$album[2]


#Adding a new variable
music_new$sales <- c("3000", "400", "755", "656", "69") #IMPORTANT !!!! USED A LOT




# activity 2.11 -----------------------------------------------------------

countryName <- c("Ireland", "Czechia", "Slovakia")
countryPop <- c(5360000,10530000,5450000)
countryDemRate <- c("Full Democracy", "Flawed Democracy", "Flawed Democracy")
countryGDP <- c(976719, 432597, 168897)
countryGini <- c(29,25.7,23.8)
countryID <- seq(1,3)

countryTable <- data.frame(countryName, countryPop, countryDemRate, countryGDP, countryGini, countryID)


#central tendency
?mean
mean(countryTable$countryPop, na.rm = 1) #na.rm ODDELA VSECHNY CHYBEJICI (NA) HODNOTY

median(countryTable$countryPop)

#barplot

?barplot
barplot(countryTable$countryPop, names.arg = countryTable$countryName, main = "Population values")



