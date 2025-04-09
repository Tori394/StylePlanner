<h1 align="center">👗 Style Planner</h1>

<p align="center">
  A virtual wardrobe manager that helps you plan outfits and save your favorite clothing combinations.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue.svg">
  <img src="https://img.shields.io/badge/GUI-Qt-informational">
  <img src="https://img.shields.io/badge/Status-Finished-brightpurple">
</p>

---

## 🧥 Features

- Browse up to **200 tops** and **200 bottoms**
- Each item includes:
  - a **path to the image** (copied to the app folder)
  - a **counter** of how often it's used in outfits
- Preview and match clothing in real-time using **arrow buttons**
- Save outfit combinations to **Favorites** with a ⭐ click
- View and manage favorites in a dedicated **second tab**

---

## 💾 Persistent Storage

- All added images and favorite outfits are **automatically saved on exit**
- Data is reloaded on the next startup from **text files**

---

## 🗑️ Smart File Management

- Images are stored and removed efficiently:
  - Deleting a clothing item also deletes the file from storage
  - Prevents duplicate files and unnecessary clutter
- You **cannot delete** an item used in any saved outfit
  - Must remove the outfit first

---

## 🛡️ Error Handling

Handled edge cases include:

✅ Invalid or duplicate file paths  
✅ Trying to remove in-use images  
✅ Deleting when nothing is added  

---

## 🧰 Built With

- **Language**: C++
- **GUI**: Qt Designer
- **Framework**: Qt

