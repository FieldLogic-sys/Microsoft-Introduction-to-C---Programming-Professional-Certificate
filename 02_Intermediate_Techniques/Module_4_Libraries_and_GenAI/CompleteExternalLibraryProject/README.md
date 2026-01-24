# Technical Documentation: Multi-Site Web Scraper
**Project:** External Library Integration (libcurl)  
**Developer:** Tony  
**Date:** January 2026

---

## 📋 1. Implementation Details

### Library Selection: `libcurl`
`libcurl` was chosen as the core networking engine due to its industry-standard reliability for handling HTTP/HTTPS protocols. It allows the application to perform robust data transfers and provides critical metadata, such as HTTP response codes.

### Build Environment & Modular Structure
The project is split into separate files to follow the principle of **Separation of Concerns**:
* **`NetworkManager.h`**: The "Contract." Defines the class and static tools.
* **`NetworkManager.cpp`**: The "Plumbing." Handles the C-style libcurl logic and the `WriteCallback`.
* **`main.cpp`**: The "Manager." Handles file I/O, user interaction, and data logging.

**Compilation Command:**
`g++ main.cpp NetworkManager.cpp -o multi_scraper -lcurl`

---

## 🚀 2. The "From Scratch" Logic Map
*Follow these steps to replicate the core functionality of this project:*

1.  **Define the Header:** Include `<string>` and use **Header Guards** (`#ifndef`) to prevent redefinition errors.
2.  **Create the Callback:** Implement a `WriteCallback` to catch raw data chunks and `append` them to a C++ string.
3.  **Setup libcurl:** * Initialize globally with `curl_global_init`.
    * Set options: `CURLOPT_URL`, `CURLOPT_WRITEFUNCTION`, and `CURLOPT_WRITEDATA`.
4.  **Sanitize Input:** Use a `trim` function (`find_first_not_of`) to remove whitespace from URLs read from a file.
5.  **Single Source of Truth:** Fetch the URL **once** per loop. Store the HTML and its length in variables immediately so that Terminal output and CSV output match exactly.
6.  **Formatted Output:** Use `<iomanip>` tools like `std::fixed` and `std::setprecision(2)` to convert raw bytes into readable KB.
7.  **Cleanup:** Close all file streams and call `curl_global_cleanup`.

---

## 🛠️ 3. Internal Learning List (Commands & Concepts)

### String & Math Operations
* **`std::string::npos`**: A constant representing "not found." Used to validate search results.
* **`size_t`**: The unsigned integer type used for byte counts and string lengths.
* **`1024 Divisor`**: Used to convert Bytes to KB (1024 bytes = 1 KB in binary systems).

### Stream Manipulation (`<iomanip>`)
* **`std::fixed`**: Prevents scientific notation for decimals.
* **`std::setprecision(2)`**: Limits output to two decimal places.
* **Escaping Quotes (`\"`)**: Used in CSV logging to ensure titles containing commas do not break the spreadsheet columns.

### Networking Logic
* **`curl_easy_setopt`**: Configures the request settings.
* **`responseCode`**: Captured via `curl_easy_getinfo` to verify if a site is up (200) or blocked (403).
* **Pass by Reference (`&`)**: Used in `long& responseCode` to allow the NetworkManager to update a variable residing in `main`.

---

## 🚧 4. Reflection: Challenges & Decisions

### Challenge: Dynamic Data & Consistency
**Hurdle:** Initially, the Terminal and CSV logs showed slightly different byte counts for the same URL.
**Discovery:** Web content (like Google) is dynamic and changes between fetches. 
**Solution:** Captured the `html` string once and derived all sizes and titles from that single "snapshot."

### Challenge: Variable Scope (Shadowing)
**Hurdle:** Variable redefinition errors occurred when declaring `std::string currentUrl` inside and outside the loop.
**Solution:** Declared the variable once and assigned values to it within the loop, ensuring the CSV logger always had access to the data.

### Challenge: 403 Forbidden Errors
**Hurdle:** Sites like Wikipedia blocked the scraper.
**Strategy:** Instead of crashing, the code was designed to initialize the `title` as "N/A" and log the 403 status code to the CSV, maintaining the integrity of the report.

---

## ✅ Success Checklist
* [x] Library (`libcurl`) integrated and compiled successfully.
* [x] Input URLs are sanitized via `trim()`.
* [x] Results are exported to a professional `results.csv`.
* [x] Human-readable formatting applied using `setprecision`.