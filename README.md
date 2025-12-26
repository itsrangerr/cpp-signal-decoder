# 📡 The Signal Decoder - C++ Console App

## 📢 Author's Note
> **Topic:** Array Manipulation & Algorithms
>
> - 🌏 **I'm not good at English!**
> - 🤖 Gemini only helped me complete the comments and translation.
> - 👨‍💻 **All code is mine, no copy.**
> - ⏱️ This topic took me **60 minutes**.

## 📝 About The Project
This project is a solution to a "Signal Decoding" problem for my programming course.
The goal is to process a raw array of integers (signal) through a series of strict logical steps: Filtering, Sorting, and Analyzing.

## 📋 Problem Statement (The Mission)
**Context:** You receive a digital signal (an integer array). Your task is to write a program using **Functions** to "clean" and "decode" it.

### ⛔ Technical Constraints (Hardcore Rules)
1.  Must split logic into **Functions**.
2.  **NO AUXILIARY ARRAYS allowed.** All deletion and sorting operations must be performed **In-place** (directly on the original array).

---

### 🛠️ Processing Steps

#### Step 1: Input
* Enter the number of elements `n` (0 < n <= 100).
* Input the values for the array.

#### Step 2: Remove Noise
* **Definition:** "Noise" is defined as **Perfect Squares** (1, 4, 9, 16, 25...).
* **Task:** Remove all perfect squares from the array.
* **Requirement:** After removal, shift the remaining elements to fill the gaps and update `n`.

#### Step 3: Special Sort (Normalization)
Sort the remaining array based on the following rules:
* **Odd Numbers:** Move to the **FRONT** and sort **Ascending**.
* **Even Numbers:** Move to the **BACK** and sort **Descending**.
* *Example:* `{2, 5, 7, 8, 1, 6}` → Output: `{1, 5, 7, 8, 6, 2}`

#### Step 4: Analysis
* Find and print the **First Pythagorean Triplet** (a, b, c) found in the array.
* Condition: `a^2 + b^2 = c^2` (or any permutation).

---

## 🧪 Test Case Example

**Input:**
```text
n = 10
Arr = { 4, 3, 9, 12, 5, 16, 25, 4, 13, 8 }
