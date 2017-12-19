
# Hardware

- Clock speed: 30MHz

- RAM: 4MB at 600MB/s

- Display resolution: 180x135
- Display color: 6-bit index + 2-bit flags

- ROM: 16MB at 200MB/s

# Software

## Stack

- Stack size: 64KB

## Types

Every stack value has a type as set when pushed.

It can be one of:

- `byte`: Unsigned 8-bit integer
- `sbyte`: Signed 8-bit integer
- `word`: Unsigned 16-bit integer
- `sword`: Signed 16-bit integer

## Instructions (stack)

### `push <type> <value>`

Push a value onto the stack.

### `cast <type>`

Cast the top stack value to a different type.

Note: Has the ability to change the value's data if required.

### `pop`

Pops the top value off the stack.

### `dup`

Duplicates the top value on the stack.

### `swap`

Swaps the two top values on the stack.

## Instructions (arithmetic)

### `neg`

Negates the top value on the stack.

Note: No-op for unsigned numbers

### `add`

Adds the top stack value to the penultimate stack value.

### `mul`

Multiply the penultimate stack value by the top stack value.

### `div`

Divide the penultimate stack value by the top stack value.

## Instructions (binary)

### `rotl`

Rotate the top stack value's bits leftwards.

### `rotr`

Rotate the top stack value's bits rightwards.

### `shiftl`

Shift the top stack value's bits leftwards.

### `shiftr`

Shift the top stack value's bits rightwards.

### `not`

Bitwise not on the top stack value.

### `and`

And the penultimate stack value with the top stack value.

### `or`

Or the penultimate stack value with the top stack value.

### `xor`

Exclusive or the penultimate stack value with the top stack value.

## Instructions (control flow)

### `loop`
