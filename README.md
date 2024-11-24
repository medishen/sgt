# Snake Game: Terminal Edition 🐍

Welcome to the **Snake Game: Terminal Edition** (`sgt`), a fun and interactive game built entirely for the terminal! Navigate menus, start the game, and enjoy an engaging experience using your keyboard. This project demonstrates real-time input handling in C with terminal-based interactivity.

## Features 🚀

- **Interactive Menus**: Use arrow keys to navigate through options.
- **Real-Time Key Handling**: Responsive keyboard input using raw terminal mode.
- **Dynamic Display**: Terminal menu updates in real-time based on user input.
- **Expandable Gameplay**: Built to serve as the foundation for a terminal-based Snake Game.

## Prerequisites 📋

Ensure you have the following installed:

- A C compiler (e.g., `gcc`)
- A terminal emulator (Linux/macOS recommended)

---

## Installation 💾

You have two options to install and run **Snake Game: Terminal Edition** (`sgt`):

### **Option 1: Installation via Cloning the Repository**

1. **Clone the Repository**

   Open your terminal and clone the repository:

   ```bash
   git clone https://github.com/medishen/sgt.git
   cd sgt
   ```

2. **Build the Program**

   Compile the source code using `make`:

   ```bash
   make
   ```

3. **Run the Program**

   After building, you can start the game by running:

   ```bash
   sgt
   ```

---

### **Option 2: Installation via Docker Image**

1. **Ensure Docker is Installed**

   Make sure you have Docker installed on your system. If not, follow the [installation instructions](https://docs.docker.com/get-docker/) for your platform.

2. **Build and Run the Docker Image**

   You can build and run the game using Docker by running the following commands:

   ```bash
   docker-compose up --build
   ```

   This will build the Docker image and start the `sgt` container, making the game available to run.

3. **Run the Game**

   Once the container is running, the game will automatically start. If you wish to interact with the game inside the Docker container, you can use:

   ```bash
   docker exec -it sgt /bin/bash
   ```

   From there, you can run the game:

   ```bash
   sgt
   ```

---

## Contributing 🤝

Contributions are welcome! For more information on how to contribute, please refer to the [CONTRIBUTING.md](./docs/CONTRIBUTING.md).

## Changelog 📜

For details on version updates, refer to the [CHANGELOG.md](./docs/CHANGELOG.md).

## Frequently Asked Questions ❓

For any questions or common issues, check out the [FAQ.md](./docs/FAQ.md).

## User Guide 📖

For detailed instructions on how to play the game, check out the [USER_GUIDE.md](./docs/USER_GUIDE.md).

## Software Requirements Specification (SRS) 📋

For a detailed technical specification of the game, please refer to the [SRS.md](./docs/SRS.md).

## License 📜

This project is licensed under the [MIT License](LICENSE).

---

### Additional Notes:

- **Docker Installation Details**:
  - The Docker setup includes a `Dockerfile` and `docker-compose.yml` for building and running the game.
  - The Docker image is configured to run the game automatically once the container is started.
- **Build Details in Docker**:
  The Dockerfile sets up the necessary environment, installs dependencies, compiles the source code, and makes the executable available in `/usr/local/bin/sgt`.
