import time

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC



options = webdriver.ChromeOptions()
options.binary_location = "(lokalizacja chrome.exe, najprawdopodobniej cos w rodzaju: Program Files\Google\Chrome\Application\chrome.exe")
chrome_driver_binary = r"(Lokalizacja chromedriver.exe, najprawodobodobniej cos w rodzaju: user\.cache\selenium\chromedriver\win32\chromedriver.exe")
driver = webdriver.Chrome(chrome_driver_binary, chrome_options=options)
driver1 = webdriver.Chrome(chrome_driver_binary, chrome_options=options)
driver2 = webdriver.Chrome(chrome_driver_binary, chrome_options=options)
driver3 = webdriver.Chrome(chrome_driver_binary, chrome_options=options)
driver4 = webdriver.Chrome(chrome_driver_binary, chrome_options=options)
driver.get("https://my.replika.com/login")
driver1.get("https://www.tlumaczangielskopolski.pl")
driver2.get("https://www.speechtexter.com/")
driver3.get("(adres esp 8266 (192.161...))")
driver4.get("tlumacz google w przegladarce")
email = driver.find_element("id", "login-email")
pas = driver.find_element("id", "login-password")
email.send_keys("replika email")
pas.send_keys("replika haslo")
pas.send_keys(Keys.RETURN)

result = driver1.find_element("id", "results-body")
inp = driver1.find_element("id", "source")
swa = driver1.find_element("id", "lang-swap").click()
elem = WebDriverWait(driver, 30).until(
EC.presence_of_element_located((By.ID, "send-message-textarea")) 
)

search_box = driver.find_element("id", "send-message-textarea")

bt = driver1.find_element("id", "translate-btn")
cpb = driver1.find_element("id", "copy-btn")
time.sleep(8)
mik = driver2.find_element("id", "note")
ilo = driver2.find_element("id", "word-counter")

inppa = driver3.find_element('id', "inppa")

butb = driver3.find_element('id', "butt")
inptb = driver4.find_element(By.CSS_SELECTOR, ('textarea[class="tw-ta tw-text-large q8U8x goog-textarea"'))
word = 'Robot'

while True:
    
 
    
    
        

    xa = mik.text
    

    if(len(xa) > 1):

        
        
        time.sleep(1)
        x = mik.text
        print(x)
        if word in x:
            mik.clear()
            time.sleep(7)
            x = mik.text
            inp.send_keys(x)     
            bt.click()
            time.sleep(2)
            cpb.click()
    
            search_box.send_keys(Keys.CONTROL + "v")
            search_box.send_keys(Keys.RETURN)
        
            inp.clear()
            mik.clear()
            time.sleep(7)

    
            img_lista = driver.find_elements(By.CSS_SELECTOR, ('div[class="BubbleText__BubbleTextContent-sc-1bng39n-1 hvuwYF"]'))
            las = img_lista[len(img_lista)-1]
            
            b = las.text
            print(b)
            inpa = driver3.find_element('id', "inp")
            buta = driver3.find_element('id', "but")
            inpa.send_keys(b)
            buta.click()
            time.sleep(2)
            ret = driver3.find_element(By.CSS_SELECTOR, ('a[href=\"/\"]'))
            ret.click()
            inptb.send_keys(b)
            time.sleep(3)
            btnr = driver4.find_element(By.ID, "tw-spkr-button")
            btnr.click()
            time.sleep(3)
            inptb.clear()
            
        else:
            inpa = driver3.find_element('id', "inp")
            buta = driver3.find_element('id', "but")
            inpa.send_keys(x)
            buta.click()
            time.sleep(1)
            ret = driver3.find_element(By.CSS_SELECTOR, ('a[href=\"/\"]'))
            ret.click()
            mik.clear()
            
