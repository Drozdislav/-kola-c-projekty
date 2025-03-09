from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.chrome import ChromeDriverManager
import time

# Initialize the Chrome driver
driver = webdriver.Chrome(ChromeDriverManager().install())

# Go to the login page
driver.get('http://jidelna.gvid.cz/faces/login.jsp')  # Replace with your actual login URL

# Wait until the page is fully loaded
time.sleep(2)

# Enter the username and password
username = driver.find_element(By.ID, 'j_username')
password = driver.find_element(By.ID, 'j_password')

# Replace with your login credentials
username.send_keys('drozd1439')  # Replace with your username
password.send_keys('J@kub1979')  # Replace with your password

# Find the login button and click it
login_button = WebDriverWait(driver, 10).until(
    EC.element_to_be_clickable((By.XPATH, "//input[@type='submit' and @value='Přihlásit']"))
)
login_button.click()

# Wait until login is complete and the page URL changes
WebDriverWait(driver, 20).until(EC.url_changes('http://jidelna.gvid.cz/faces/login.jsp'))

# After login, navigate to the calendar page
driver.get('http://jidelna.gvid.cz/faces/secured/main.jsp?terminal=false&android=false&keyboard=false&printer=false')  # Replace with the actual URL of the lunch selection page

# Wait for the calendar to load and the calendar table to be visible
WebDriverWait(driver, 20).until(EC.visibility_of_element_located((By.CSS_SELECTOR, 'td.KalTable')))

try:
    # Find all the calendar day <td> elements
    days = driver.find_elements(By.CSS_SELECTOR, 'td.KalTable')  # All td elements with the class 'KalTable'

    # Loop through the days and select all yellow days (unselected)
    for day in days:
        # Get the background color of the day button
        button_style = day.get_attribute('style')

        # Check if the background color is the specific unselected color (yellow)
        if 'background-color: #FBE983' in button_style:  # Match the unselected yellow color
            # Get the day number from the <div> tag inside <td>
            day_number = day.find_element(By.TAG_NAME, 'div').text
            # Wait for the day to be clickable, then click it
            WebDriverWait(driver, 10).until(EC.element_to_be_clickable(day))
            day.click()
            print(f"Successfully selected day {day_number}!")

            # Wait a bit to confirm the action before continuing to the next day
            time.sleep(1)  # Adjust if needed to avoid clicking too quickly

    # Find the first lunch choice button ('Oběd 1')
    button = driver.find_element(By.XPATH, "//a[@class='btn button-link button-link-main enabled']//span[contains(text(), 'Oběd 1')]")

    # Wait for the button to be clickable
    WebDriverWait(driver, 10).until(EC.element_to_be_clickable(button))
    # Click the button
    button.click()
    print("Successfully selected 'Oběd 1'!")

    # Wait a bit to confirm the action
    time.sleep(2)

except Exception as e:
    print(f"Error occurred: {e}")

# Wait a few seconds before closing the browser
time.sleep(5)

# Close the browser
driver.quit()
