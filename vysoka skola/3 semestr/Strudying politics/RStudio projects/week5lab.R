library(Hmisc) #for importing data
library(dplyr) #for data manipulation (e.g., count)

trans <- read.csv("data/transphobia.csv")
data <- spss.get("data/nilt25w2.sav", to.data.frame = TRUE)
getwd()

nat <- subset(data, !UNTDIREL %in% c("I don't know")) #gets ridd off all things that says i dont know
nat <- droplevels(nat) #remove all things that are empty because we removed i dont know it is empty

#cross table

cross_tab <- table(nat$UNTDIREL, nat$RSEX)
cross_tab

prop_tab <- prop.table(cross_tab, margin = 2) * 100 #proportions - creates percentages
prop_tab

chisq.test(cross_tab) #if it is significant it is lower than .05

library(DescTools)
CramerV(cross_tab) #weak relationship because lower than .02??

barplot(prop_tab, legend.text = T, beside = T) #?????????? do pice



# the trans dataset -------------------------------------------------------

#did treatment work
mean(trans$tolerance.t0)
mean(trans$tolerance.t1, na.rm = T)

#treatment distinguished between placebo and treatment

mean(trans$tolerance.t1[trans$treatment.delivered  == T], na.rm = T)
mean(trans$tolerance.t1[trans$treatment.delivered  == F], na.rm = T)

