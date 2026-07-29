

# C++ Cross-Platform Digital Clock ⏰

A lightweight, real-time C++ console application designed to display continuous system time while demonstrating low-level C++ time management, memory structures, and cross-platform refactoring.

---

## Key Features

* **Real-Time Display Update:** Uses a continuous execution loop to update and re-render system time every second without overloading CPU execution.
* **Formatted Time Outputs:** Utilizes stream manipulation (`<iomanip>`) and standard C++ time format specifiers (`%H:%M:%S`) to output clean, readable time data.
* **Cross-Platform Compatibility:** Refactored away from OS-specific Windows API headers (`<windows.h>`, `Sleep()`, `cls`) to native modern C++ standard threading (`std::this_thread::sleep_for`) and cross-platform standard libraries.

---

## My Learning Takeaways

Built as part of a hands-on **Project-Based C++ Learning Journey** to move away from passive tutorials and master practical concepts:

1. **System Time vs. Human Time:** Learned how raw machine clock ticks (`std::chrono::system_clock`) convert into Unix epoch seconds (`time_t`), and how pointer memory addresses (`&currentTime`) pass into structural translators (`tm*` via `localtime`).
2. **Standardizing Thread Delays:** Understood why replacing platform-locked functions like `Sleep(1000)` with `std::this_thread::sleep_for(std::chrono::seconds(1))` makes the codebase clean and portable across macOS, Linux, and Windows.
3. **Explicit Namespace Resolution:** Resolved subtle compiler errors by directly specifying nested scopes (such as `std::chrono::seconds` and `std::this_thread`) rather than relying on broad imports.

---

## How to Compile and Run (Terminal)

### On Linux / macOS / Windows (GCC/Clang):
```bash
g++ DigitalClock.cpp -o DigitalClock
./DigitalClock
