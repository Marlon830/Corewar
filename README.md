<div align="center">

```
   ██████╗ ██████╗ ██████╗ ███████╗██╗    ██╗ █████╗ ██████╗
  ██╔════╝██╔═══██╗██╔══██╗██╔════╝██║    ██║██╔══██╗██╔══██╗
  ██║     ██║   ██║██████╔╝█████╗  ██║ █╗ ██║███████║██████╔╝
  ██║     ██║   ██║██╔══██╗██╔══╝  ██║███╗██║██╔══██║██╔══██╗
  ╚██████╗╚██████╔╝██║  ██║███████╗╚███╔███╔╝██║  ██║██║  ██║
   ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝
```

**Programs fight to the death inside a 6KB memory arena.**

*Fully implemented in C.*

</div>

---

## What is Corewar?

Corewar is a classic programming game invented in 1984. You write programs in a custom assembly language, called **champions**, and pit them against each other inside a circular virtual memory. The last champion to prove it is still alive wins.

This repository contains a full implementation of the Corewar system:

| Component | Binary | Role |
|---|---|---|
| Assembler | `asm/asm` | Compiles `.s` source files into `.cor` champion binaries |
| Virtual Machine | `corewar/corewar` | Loads champions and runs the battle |
| Graphical Client *(bonus)* | `bonus/src/graphic/corewar` | 3D real-time visualization over the network |
| Server *(bonus)* | `bonus/src/server/server` | Streams VM state to graphical clients |

---

## Building

```sh
# Build both the assembler and the VM
make

# Build the bonus graphical client + server
make bonus_all

# Rebuild everything from scratch
make re

# Clean
make clean    # object files only
make fclean   # object files + binaries
```

---

## Usage

### Assembler

```sh
./asm/asm <champion.s>
```

Produces a `<champion.cor>` binary next to the source file.

```sh
./asm/asm -h    # show help
```

### Virtual Machine

```sh
./corewar/corewar [options] <champion1.cor> [champion2.cor ...]
```

| Flag | Description |
|---|---|
| `-dump <N>` | Dump the arena to stdout every N cycles then exit |
| `-n <N>` | Force a specific program number for the next champion |
| `-a <addr>` | Load the next champion at a specific address in the arena |

Up to **4 champions** can battle simultaneously. The last one to have executed a `live` instruction within the liveness window wins.

---

## Writing a Champion

Champions are written in a custom assembly language. Here is a minimal example:

```asm
.name "Warrior"
.comment "I am inevitable."

    live %1
    zjmp %:alive

alive:
    live %1
    zjmp %:alive
```

### Instruction Set

| Instruction | Cycles | Description |
|---|---|---|
| `live %N` | 10 | Declare champion N is alive, the core survival mechanic |
| `ld <val>, r<N>` | 5 | Load a value into a register |
| `st r<N>, <dest>` | 5 | Store a register to memory or another register |
| `add r1, r2, r3` | 10 | r3 = r1 + r2 |
| `sub r1, r2, r3` | 10 | r3 = r1 − r2 |
| `and`, `or`, `xor` | 6 | Bitwise operations → result register |
| `zjmp %<label>` | 1 | Jump if carry flag is set |
| `ldi`, `sti` | 25 / 25 | Indirect indexed load / store (offset modulo `IDX_MOD`) |
| `lld`, `lldi` | 10 / 50 | Long variants: no `IDX_MOD` wrapping |
| `fork %<label>` | 800 | Spawn a new process at PC + (offset % `IDX_MOD`) |
| `lfork %<label>` | 1000 | Long fork: no `IDX_MOD` wrapping |
| `aff r<N>` | 2 | Print the ASCII character stored in a register |

Each champion starts with **16 registers** (`r1`–`r16`). The arena wraps around at **6144 bytes**.

---

## Arena & VM Mechanics

```
MEM_SIZE       = 6144 bytes   (6 KB circular arena)
REG_NUMBER     = 16           (registers per process)
CYCLE_TO_DIE   = 1536         (liveness window at start)
NBR_LIVE       = 40           (live calls required to reduce CYCLE_TO_DIE)
IDX_MOD        = 512          (short addressing modulo)
```

Every `CYCLE_TO_DIE` cycles, the VM checks whether each process has executed a `live` instruction recently enough. Processes that haven't are killed. The window shrinks as the game progresses, forcing champions to fight more aggressively over time.

---

## Bonus - 3D Graphical Client & Server

The bonus extends the project into a networked, real-time visualization system.

### Architecture

```
┌──────────────────────┐        TCP Socket         ┌──────────────────────┐
│   Graphical Client   │ ◄────────────────────────► │       Server         │
│   (Raylib / OpenGL)  │    arena + champion state   │   (Corewar VM)       │
└──────────────────────┘                             └──────────────────────┘
        │
  pthread (network thread)
  fetches data asynchronously
  while main thread renders
```

### Server

Runs the full Corewar VM internally and listens on a TCP port for client connections. On each client request, it executes the VM up to the requested cycle and serializes the full arena and champion state over the socket.

### Graphical Client

Built with **[Raylib](https://www.raylib.com/)** and renders the arena in **3D** using OpenGL.

**Technical highlights:**
- **Multi-threaded** a dedicated `pthread` handles all network I/O asynchronously, keeping the render loop smooth and non-blocking
- **3D rendering** the 6KB arena is visualized as a 3D grid using Raylib's `BeginMode3D` / `EndMode3D`, with each memory cell coloured by its owning champion
- **Camera controls** free 3D camera orbit around the arena
- **Audio** background music and sound effects via Raylib's audio device
- **Interactive UI** main menu, IP/port connection dialog, fullscreen toggle
- **Live streaming** arena state updates in real time as the server simulates the battle

### Running the Bonus

```sh
# Start the server with your champions
./bonus/src/server/server <port> <champion1.cor> [champion2.cor ...]

# Launch the graphical client
./bonus/src/graphic/corewar
# Then enter the server IP and port in the connection dialog
```

---

## Project Structure

```
.
├── asm/                  # Assembler
│   ├── include/          # asm.h, op.h
│   └── src/              # Compiler pipeline (two-pass)
├── corewar/              # Virtual machine
│   ├── include/          # corewar.h, op.h
│   ├── init/             # Argument parsing, champion loading, arena init
│   ├── execute/          # Main cycle loop, liveness management
│   └── all_instructions/ # One file per instruction (16 total)
├── bonus/
│   └── src/
│       ├── graphic/      # Raylib 3D client (multithreaded)
│       └── server/       # TCP server wrapping the VM
├── champions/            # Assembly source examples (.s files)
└── champion_keynotes/    # Pre-compiled .cor champion binaries
```

This project was developed during the first year of study.
