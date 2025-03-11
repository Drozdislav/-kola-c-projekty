from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.microsoft import EdgeChromiumDriverManager
from selenium.webdriver.edge.service import Service as EdgeService
import time

# Initialize Edge WebDriver using WebDriver Manager
service = EdgeService(EdgeChromiumDriverManager().install())
driver = webdriver.Edge(service=service)

# Define URLs
login_url = 'http://jidelna.gvid.cz/faces/login.jsp'
main_url = 'http://jidelna.gvid.cz/faces/secured/main.jsp?terminal=false&android=false&keyboard=false&printer=false'

# Open login page
driver.get(login_url)

# Wait for the page to load
time.sleep(2)

# Enter login credentials
username = driver.find_element(By.ID, 'j_username')
password = driver.find_element(By.ID, 'j_password')

# Replace with your credentials
username.send_keys('drozd1439')
password.send_keys('J@kub1979')

# Click the login button
login_button = WebDriverWait(driver, 10).until(
    EC.element_to_be_clickable((By.XPATH, "//input[@type='submit' and @value='Přihlásit']"))
)
login_button.click()

# Wait until login is complete
WebDriverWait(driver, 20).until(EC.url_changes(login_url))

# Start processing lunches
while True:
    # Go to the main page
    driver.get(main_url)

    # Wait for the page to load
    time.sleep(2)

    # Find any yellow (unselected) lunch buttons
    yellow_buttons = driver.find_elements(By.CSS_SELECTOR, "td.KalTable.Kal1")

    if not yellow_buttons:
        print("Lunches already selected")
        break

    # Click the first available yellow button
    yellow_buttons[0].click()
    print("Selected a lunch day")

    # Wait for the lunch selection button to appear
    try:
        order_button = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.XPATH, "//a[contains(@class, 'button-link-main') and .//span[contains(text(), 'Oběd 1')]]"))
        )
        order_button.click()
        print("Ordered 'Oběd 1' successfully")
    except Exception as e:
        print(f"Error selecting lunch: {e}")
        break

    # Short delay before checking again
    time.sleep(2)

# Close the browser
driver.quit()
