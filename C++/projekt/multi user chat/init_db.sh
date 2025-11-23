#!/bin/bash
DB="chat.db"
echo "Create $DB ..."
rm -f "$DB"
sqlite3 "$DB" > /dev/null <<SQL
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT UNIQUE NOT NULL,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS messages (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    content TEXT NOT NULL,
    sent_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY(user_id) REFERENCES users(id)
);

INSERT OR IGNORE INTO users (username) VALUES ('Admin'), ('Karen'), ('Հակոբ');
INSERT INTO messages (user_id, content) 
SELECT 1, 'Hello evryone' UNION ALL
SELECT 2, 'Hi Admin' UNION ALL
SELECT 3, 'thenkyu for create chat';

SELECT 'Baza is ready! Users՝ ' || COUNT(*) FROM users;
SQL
echo "chat.db is create and ready for runing!"
