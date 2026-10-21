#load the Hmisc package
library(Hmisc) #for importing data
library(dplyr) #for data manipulation (e.g., count)

data <- spss.get("data/nilt25w2.sav", to.data.frame = TRUE)

tab <- table(data$LOYMURAL)
props <- prop.table(tab)
barplot(props, main = "People offended by loayalist murals")

#prop table creates proportions (like percentages)

# nominal data ------------------------------------------------------------

tab2 <- table(data$UNINATID)
props2 <- prop.table(tab2)
barplot(props2, main = "Do you think yourself as L or NA or you dk?",
        cex.names = 0.7,
        xlab = "Identity", #names the x axis
        ylab = "Percentage") #names the y axis

tab2 <- tab2[c("Unionist", "Nationalist", "Neither")] #leaves only the three categories

barplot(tab2)


# ordinal data ------------------------------------------------------------

untab <- table(data$UNTDIREL)
barplot(untab)
untab <- sort(untab)
barplot(untab)

propuntab <- prop.table(untab)
pie(propuntab)


# subsetting --------------------------------------------------------------

data$UNIRE_simple <- ifelse(data$UNTDIREL %in% c("Very likely", "Quite likely"), "Likely",
                            ifelse(data$UNTDIREL %in% c("Very unlikely", "Quite unlikely"), "Unlikely",
                                   as.character(data$UNTDIREL)))

#Lets look at the data
table(data$UNIRE_simple)



# activity ----------------------------------------------------------------

data$REPMURAL

murtab <- table(data$REPMURAL)
propmur <- prop.table(murtab)

barplot(propmur)


# testing relationships bewteen two variables ------------------------------
table7 <- table(data$UNINATID,data$UNTDIREL)
prop <- prop.table(table7, margin = 2)
prop_round <- round(prop, digits = 2)
prop_round
chisq.test(table7)$expected

nat <- subset(data, UNINATID %in% c("Unionist", "Nationalist", "Neither") &
                UNTDIREL %in% c("Very likely", "Quite likely", "Even chance", "Quite unlikely", "Very unlikely"))

#we can tell R to keep only certain labels
nat$UNTDIREL <- factor(nat$UNTDIREL, levels = c("Very unlikely", "Quite unlikely", "Even chance", "Quite likely", "Very likely"))
nat$UNINATID <- factor(nat$UNINATID, levels = c("Unionist", "Nationalist", "Neither"))

#Now lets look at the table
tab <- table(nat$UNTDIREL, nat$UNINATID)
tab


# cramer V ----------------------------------------------------------------

install.packages("DescTools") #this gives us a package to calculate cramers v
library(DescTools)
