
Specification sheet for Proto16.

# Hardware

## CPU

- 16-bit
- Clock speed: 30MHz
- Big endian

## GPU

- Scaled sprite rendering (Up to 32x32 resolution)
- Triangle rendering

The color and depth buffers are only written to via microcode and read only when flushing the buffer(s) to the screen.

### Microcode

Microcode is a data block in VRAM, and it is run on every rendered pixel with these inputs:

- Pixel index (u16)
- Pixel color (Depends)
- Pixel depth (u8)
- Direction ratio (u8) (Ratio of surface area to visible area)

And has access to VRAM (But not RAM)

## Memory

- ROM cartridge: 32MB at 300MB/s
- Persistent storage: 16KB
- RAM: 64KB at 600MB/s
- VRAM: 64KB internal

## Controls

Uses are optional and simply a recommendation.
If an action ingame fits a use listed below, you should use it for consistency if possible.

- `Start`: Pause/menu
- `Select`: Game-related menu (Inventory, weapons, etc.)
- `A`: Primary action (Shoot, attack)
- `B`: Secondary action (Use, interact)
- `C`: Mechanic/modifier (Hold to interact with the D-pad)
- `D-pad`: 4 directional buttons (Movement etc.)

## Graphics

- Resolution: 256x144

### Color modes

Color modes are global across ALL rendering including sprites and the color buffer

- `I1`: 1-bit indexed
- `I4`: 4-bit indexed, index 0 is alpha
- `I8`: 8-bit indexed, index 0 is alpha

## Audio

- 8KHz 16-bit samples
- Channels: 4 (Mono)

# Software

## Syntax

Names can contain `[_a-zA-Z0-9]` but must start with `[_a-zA-Z]`.

Any line beginning with period (`.`) is a preprocesser directive, aka pseudo-op.

Constants are numbers statically compiled (They have no address) and start with `[-0-9]`
If a constant starts with `0x` it is a hexidecimal number. For example `0x21`.
If a constant starts with `0o` it is an octal number. For example `0o41`.

Operands can be one of:

- Pointer
- Register
- Constant

Operands wrapped in brackets (`[]`) are pointers and are in the format `[ptr]` or `[ptr:offset]`, where `offset` is an offset in bytes from `ptr`.

If an operand starts with greater than sign  (`>`) followed immediately by a type, the operand will be treated as that type, if applicable.

Labels are defined by a valid symbol name with a colon (`:`) appended to it.

If a line has an unescaped pound sign (`#`), the rest of the line is ignored and is a comment.

## Pointers

Pointers are for accessing RAM (Or VRAM, in the case of microcode)

## Data types

Data sizes:

- `nibble`: 4-bit value
- `byte`: 8-bit value
- `word`: 16-bit value

Registers have a fixed size and cannot be type cast.

### Example syntax

```
.global _start # Keep reference to _start so an external source can enter the program

.segment data
message:
.data bytes, "Hello, world!"
message_len:
.expr sub, message_len, message

.segment code
_start:
    mov dl, 4 # Random number for now; GPU command index for caching a sprite
    mov ax, [0x7d3a:0x4b2f] # Pointer to the start of the sprite data in ROM
    int 7 # Random number; GPU interrupt

    mov dl, 5 # Random number for now; GPU command index for pushing AX to the draw parameters
    mov ax, 40 # X position of sprite
    int 7
    mov ax, 20 # Y position of sprite
    int 7
    mov ax, 511 # X scale of sprite (0.0 to 1.0 is mapped as 0-255, negative numbers flip this axis)
    int 7
    mov ax, 255 # Y scale of sprite
    int 7

    mov dl, 6 # Random number for now; GPU command index for drawing a sprite
    int 7
```

## Stack

The stack uses LIFO ordering and can hold 128 16-bit values.

## Registers

### Data registers

4x 16-bit

- `AX`
- `BX`
- `CX`
- `DX`

8x 8-bit (2 per 16-bit register):

- `AL` (Least significant half)
- `AH` (Most significant half)
- `BL`
- `BH`
- `CL`
- `CH`
- `DL`
- `DH`

### Miscellaneous registers

- `BP` (Stack base pointer; used for subroutine stack state)
- `SP` (Stack pointer; current stack pointer)
- `IP` (Current instruction address)

### Flag register

- `FLAGS` (16-bit status flags)
  - 0: `ZF` (Zero flag)
  - 1: `CF` (Carry flag)
  - 2: `SF` (Sign flag)
  - 3: `OF` (Overflow flag)

  - 8: `DF` (Direction flag)

## Pseudo-opcodes

### `.segment <type>`

Specifies what type of data is after this marker.

Can be one of:

- `data` (Always placed at the end of the compiled program, so it can also function as a pointer to the end of the preloaded program)
- `code`

The data segment is raw binary data. Some pseudo-ops allow writing binary data from more common data forms such as strings and numbers.

### `.global <symbol>`

Instructs the compiler to add a symbol to the symbol table for external uses.

### `.include <file>`

Directly copies another file into the current file at compile time.

### `.define <name>, <value>`

Replaces a name with a value at compile time.

### `.data <type>, <data>`

Insert a block of raw data, the length is determined by the data sequence until the end of the line and is in the format of a string or an arbitrary amount of comma seperated constants.

Type is a data size type.

### `.zero <length>`

Pad a chunk of data with zeroes, mainly applicable in the data segment.

## Opcodes

Instruction data:

- Byte: opcode number
- Byte: number of operands
- Byte: operand flags (1:ptr/reg/const, 4:size)
  - Data for operand(s)
- ... additional operands

### `NOP`

No-op.

### `INT <id>`

Interrupt request.

Interrupts read data from *DX*, the exact type and what formt of the data depends on the interrupt.
If an interrupt requires a secondary command index it is read from *DL*.

### `LEA <dest>, <src>`

Copies a memory pointer to a register.

### `MOVE <dest>, <src>`

Move a register or memory to a new location.

### `SWAP <reg>, <reg>`

Swap two registers.

### `INC <reg>`

Increment register by 1.

### `DEC <reg>`

Increment register by 1.

### `ADD <dest>, <src>, <value>`

Increment unsigned register by an arbitrary value.

### `SUB <dest>, <src>, <value>`

Subtract an arbitrary value from an unsigned register.

### `MUL <dest>, <src>, <value>`

Multiply unsigned register by an arbitrary value.

### `DIV <dest>, <src>, <value>`

Divide unsigned register by an arbitrary value.

### `SMUL <dest>, <src>, <value>`

Multiply signed register by an arbitrary value.

### `SDIV <dest>, <src>, <value>`

Divide signed register by an arbitrary value.

### `NEG <reg>`

Negate a register's value.

### `ROTL <reg>, <value>`

Rotate bits in register left (Towards the most significant bit)

### `ROTR <reg>, <value>`

Rotate bits in register right (Towards the least significant bit)

### `SHL <reg>, <value>`

Shift bits in register left (Towards the most significant bit)

### `SHR <reg>, <value>`

Shift bits in register right (Towards the least significant bit)

### `TEST <a>, <b>`

Bitwise AND but discards the data.

Result placed in ZF.

### `CMP <a>, <b>`

Compares if two values are identical.

Result placed in ZF.

### `NOT <dest>`

Bitwise NOT.

Result placed in dest.

### `AND <dest>, <src>`

Bitwise AND.

Result placed in dest.

### `XOR <dest>, <src>`

Bitwise XOR.

Result placed in dest.

### `OR <dest>, <src>`

Bitwise OR.

Result placed in dest.

### `CALL <ptr>`

Save state and jump to a pointer or label.

- *IP* is pushed to the stack
- *SP* is pushed to the stack
- Jump to pointer

### `RET`

Jump back to the calling instruction.

- Value is popped from the stack into *SP*
- *IP* is popped from the stack
- Jump to *IP*

### `JUMP <ptr>`

Jump to a pointer or label.

### `Jxx <ptr>`

Conditional jump.

Flag conditionals:

- JZ: `ZF == 1`
- JNZ: `ZF == 0`
- JC: `CF == 1`
- JNC: `CF == 0`
- JS: `SF == 1`
- JNS: `SF == 0`
- JO: `OF == 1`
- JNO: `OF == 0`

Unsigned integer conditionals:

- JB: `CF == 1`
- JBE: `(CF == 1) || (ZF == 1)`
- JAE: `CF == 0`
- JA: `(CF == 0) && (ZF == 0)`

Signed integer conditionals:

- JL: `SF != OF`
- JLE: `(SF != OF) || (ZF == 1)`
- JGE: `SF == OF`
- JG: `(SF == OF) && (ZF == 0)`

### `PUSH <src>`

Push a register onto the stack.

### `PUSHF`

Push FLAGS onto the stack.

### `PUSHA`

Push all 4 data registers onto the stack in the order *ABCD*.

### `POP <dest>`

Pop a stack value into a register.

### `POPF`

Pop FLAGS from the stack.

### `POPA`

Pop all 4 data registers from the stack in the order *DCBA*.

### `LOOP <reg> <ptr>`

As long as the register is not zero, decrement the register by one, then jump to a pointer.
