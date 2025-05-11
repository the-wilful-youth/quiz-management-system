# 📚 Quiz Management System in C

A feature-rich **Quiz Management System** built entirely in **C**, using multiple `.c` source files, with no header files. This project simulates a quiz platform for students and administrators, including functionalities like question management, user authentication, quiz participation, score evaluation, leaderboard tracking, and a "Question of the Day" streak feature.

---

## 🛠 Features

### 👤 Authentication

- Admin and user login system
- Registration for both users and admins
- Secure credentials storage using simple CSV files

### 🧑‍💻 Admin Dashboard

- Add new questions (MCQs & one-word type)
- View all quiz results
- Access Question of the Day
- Manage quiz content stored in CSV

### 🙋 User Dashboard

- Take quizzes from stored questions
- View personal quiz history
- Check the global leaderboard
- View and answer the Question of the Day (QOTD)

### 📊 Quiz Evaluation

- Automatic score calculation
- Scores saved along with usernames in `results.csv`

### 🏆 Leaderboard & History

- Global leaderboard based on average quiz scores
- Per-user quiz attempt history

### 📝 File-based Storage

- Questions (`questions.csv`)
- Question of the Day (`qotd.csv`)
- User/Admin credentials (`users.csv`, `admins.csv`)
- Quiz results (`results.csv`)

---

## 🗂️ File Structure

```bash
QuizManagementSystem_C/
├── main.c               # Main driver with dashboard navigation
├── auth.c               # Handles login and registration
├── question_mgmt.c      # Admin question management
├── quiz_conduct.c       # Quiz participation logic
├── evaluation.c         # Evaluates quiz score and stores results
├── result_mgmt.c        # Displays results, user history, leaderboard
├── qotd.c               # Manages Question of the Day and streaks
├── student_data.c       # Stores and manages student data
├── excel_utils.c        # Simulated CSV utilities
├── questions.csv        # Stored quiz questions
├── qotd.csv             # Question of the Day
├── users.csv            # Registered users
├── admins.csv           # Registered admins
├── results.csv          # Quiz attempt logs
```

---

## 🚀 Getting Started

### 🧰 Requirements

- A C compiler (e.g. `gcc`)
- Terminal or command line

### 🔧 Compilation

```bash
gcc main.c -o quiz_app
```

### ▶️ Run the App

```bash
./quiz_app
```

---

## 🧪 Sample Credentials

**Admin Login**

- Username: `admin`
- Password: `admin123`

**User Login**

- Username: `john`
- Password: `1234`

---

## 📌 Notes

- All data is persisted in `.csv` files – no external database required.
- Designed for educational/demo purposes.
- No external libraries are used – entirely built with standard C libraries.

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
