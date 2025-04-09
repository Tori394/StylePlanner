# 👗 Style Planner

**Style Planner** is a desktop application written in C++ using Qt. It allows users to browse their wardrobe virtually, plan outfits, and save favorite combinations — all without opening the closet.

---

## 🧥 Key Features

- Browse up to **200 images** of tops and **200 images** of bottoms
- Each clothing item is stored as a structure containing:
  - the file path (copied into the app's directory)
  - a counter of how many saved outfits include the item

---

## ✨ Outfit Planning & Favorites

- Navigate through added clothing items using arrow buttons
- Compare tops and bottoms side-by-side
- Save favorite outfit combinations by clicking the ⭐ button
- Favorites are displayed in a separate tab and **update dynamically**
- Remove individual outfits from favorites without breaking the layout

---

## 🗑️ Image Management

- You can only delete clothing items **not used in any saved outfits**
- When an image is removed:
  - its file is deleted from the app’s storage
  - it becomes available for re-adding later
- This keeps the app clean and prevents clutter

---

## 💾 Data Persistence

- The app **automatically saves**:
  - added clothing items
  - saved outfit combinations
- Data is stored in text files and loaded back on app startup

---

## 🛡️ Error Handling

All critical errors are properly handled:
- Invalid files (wrong name, path, or duplicates)
- Attempting to delete items used in saved outfits
- Trying to remove items when none have been added

---

## 🧰 Technologies Used

- **Language**: C++
- **GUI**: Qt Designer

---

## 📸 Screenshots


