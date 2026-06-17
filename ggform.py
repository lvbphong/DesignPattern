from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time
import random

# Đường dẫn đến ChromeDriver (thay bằng đường dẫn của bạn nếu cần)
CHROMEDRIVER_PATH = "C:/chromedriver/chromedriver.exe"  # Ví dụ cho Windows, sửa nếu dùng Mac/Linux

# URL của Google Form
FORM_URL = "https://docs.google.com/forms/d/e/1FAIpQLSdlpeV4wCaA7qAbNXsBDty902zV6jnuOgLJJzWL0iKiNQVycA/viewform"

def auto_fill_form():
    # Khởi tạo trình duyệt
    service = Service(CHROMEDRIVER_PATH)
    driver = webdriver.Chrome(service=service)
    
    try:
        # Mở Google Form
        driver.get(FORM_URL)
        time.sleep(1)  # Chờ trang tải

        # Câu hỏi 1: Chọn "Rồi"
        radio_answered = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.XPATH, "//span[text()='Rồi [Tiếp tục khảo sát]']"))
        )
        driver.execute_script("arguments[0].click();", radio_answered)


        # Chờ trang tiếp theo
        time.sleep(1)

        # Câu hỏi 2: Chọn "1 tháng"
        duration_option = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.XPATH, "//span[text()='1 tháng']"))
        )
        driver.execute_script("arguments[0].click();", duration_option)

        # Nhấn nút "Gửi"
        # submit_button = WebDriverWait(driver, 10).until(
        #     EC.element_to_be_clickable((By.XPATH, "//span[text()='Next']"))
        # )
        # driver.execute_script("arguments[0].click();", submit_button)
        next_button = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.XPATH, "//span[text()='Tiếp']"))
        )
        driver.execute_script("arguments[0].click();", next_button)

        print("Đã gửi form thành công!")
        time.sleep(3)  # Chờ xác nhận

        radio_groups = WebDriverWait(driver, 10).until(
            EC.presence_of_all_elements_located((By.XPATH, "//div[@role='radiogroup']"))
        )

        print(f"Tìm thấy {len(radio_groups)} nhóm radio buttons (tiêu chí).")

        for index, radio_group in enumerate(radio_groups):
            try:
                # Tìm tất cả radio buttons trong nhóm này
                radio_buttons = radio_group.find_elements(By.XPATH, ".//div[@role='radio']")
                if radio_buttons:
                    # Chọn ngẫu nhiên một radio button
                    random_radio = random.choice(radio_buttons)
                    driver.execute_script("arguments[0].scrollIntoView();", random_radio)
                    driver.execute_script("arguments[0].click();", random_radio)

                    # Kiểm tra xem radio button đã được chọn chưa
                    is_selected = driver.execute_script(
                        "return arguments[0].getAttribute('aria-checked') === 'true';", random_radio
                    )
                    if is_selected:
                        print(f"Tiêu chí {index + 1}: rguments[0].click() radio buttons")
                    else:
                        print(f"Tiêu chí {index + 1}: rguments[0].click() radio buttons")
                else:
                    print(f"Tiêu chí {index + 1}: arguments[0].click() radio buttons")

                time.sleep(1)  # Chờ để Google Forms ghi nhận
            except Exception as e:
                print(f"Lỗi khi chọn giá trị cho tiêu chí {index + 1}: {e}")

        # Nhấn "Gửi" (giả định đây là trang cuối)
        submit_button = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.XPATH, "//span[text()='Tiếp']"))
        )

        driver.execute_script("arguments[0].click();", submit_button)

        time.sleep(50) 

    except Exception as e:
        print(f"Lỗi xảy ra: {e}")
    
    finally:
        driver.quit()

if __name__ == "__main__":
    auto_fill_form()