<div align="left">
  <pre>
                                       __                  
                   `       `          .^o ~\  `        `   `                `
                            ``  `    Y /'~) }      _____          `        `` `
                            `       l/  / /    ,-~     ~~--.,_    `         `    ``
                       `           `   ( (    /  ~-._         ^.
                       ``      `        \ "--'--.    "-._       \       `    `
                         `           `   "-.________     ~--.,__ ^.             `
                                 `    `            \"~r-.,___.-'-. ^.
                         `    `                 `    YI    \\      ~-.\     `      `
                              `             `       ||     \\        `\
                          `                  `      ||     //
                    `           `                   ||    //
                      `           `          `       ()   //
                                  `          `      ||  //     `   `
                             `                      || ( c      `
                              `        ___._ __  ___I|__`--__._ __  _
                                     "~     ~  "~  ""   ~~"    ~  ~~
  </pre>
  <div align="center">
  <h1 style="border-bottom: none;">🦩 Flamingo Libft Tester 🦩</h1>
  <p>
    A comprehensive and personal tester for the 42 school <strong>Libft</strong> project.
    <br />
    <em>Crafted with care by QLACHENA</em>
  </p>
</div>

---

## About The Project

The **Flamingo Libft Tester** is a lightweight, single-file testing program designed to verify the functionality of every function required in the 42 `libft` project, including the bonus parts. It provides clear, color-coded feedback for each test case, making debugging a breeze.

This tester was built to be:
* **Simple:** Easy to set up and run with a straightforward Makefile.
* **Comprehensive:** Covers all mandatory and bonus functions.
* **Clear:** Compares your functions to the originals (where available) and gives detailed output.
* **Flexible:** Easily toggle bonus function testing on or off.

And of course, it rewards you with a beautiful flamingo ASCII art upon completion of the tests!

---

## Features

* **Complete Coverage:** Tests for all **Part 1**, **Part 2**, and **Bonus** functions.
* **Color-Coded Output:** `[OK]` in green for success, `[KO]` in red for failure.
* **Detailed Reports:** Each test case describes the input and the expected result.
* **Bonus Toggle:** A simple switch in the `Makefile` to include or exclude bonus function tests.
* 🦩 **A Flamingo:** Because every successful project deserves a flamingo.

---

## Getting Started

Follow these simple steps to get the tester up and running.

### Prerequisites

You must have a complete `libft` project, including its own `Makefile` that can create `libft.a` and handle a `bonus` rule.

### Folder Structure

Your project should be organized as follows for the tester to work correctly:

<pre>
.
├── libft/
│   ├── ft_.c
│   ├── ft__bonus.c
│   ├── libft.h
│   └── Makefile        # Your Libft's Makefile
│
├── main.c              # The Flamingo Tester source
└── Makefile            # The Flamingo Tester Makefile
</pre>

### Installation & Usage

1.  **Clone the repository** or place the `main.c` and `Makefile` in the root of your project, alongside your `libft` folder.

2.  **Configure the Bonus:** Open the main `Makefile` and set the `TEST_BONUS` variable:
    * Set `TEST_BONUS = 1` to test the bonus part.
    * Set `TEST_BONUS = 0` to test only the mandatory part.

3.  **Compile the tester:** Run the `make` command. This will first compile your `libft.a` (with or without the bonus files depending on your choice) and then compile the tester itself.
    ```sh
    make
    ```

4.  **Run the tests:** Execute the compiled program.
    ```sh
    ./test_program
    ```

---

## Makefile Usage

The provided `Makefile` offers several rules for easy management:

* `make` or `make all`: Compiles the tester and the libft library.
* `make clean`: Removes the object files from both the tester and the libft directory.
* `make fclean`: Removes all generated files, including the final executable (`test_program`) and the `libft.a` library.
* `make re`: Forces a full recompilation by running `fclean` then `all`. This is useful after changing configuration like the `TEST_BONUS` switch.

---

## Functions Tested

The Flamingo Tester covers the entire scope of the `libft` subject.

### Part 1 - Libc Functions

| isalpha  | isdigit | isalnum | isascii | isprint     |
| :------- | :------ | :------ | :------ | :---------- |
| strlen   | memset  | bzero   | memcpy  | memmove     |
| toupper  | tolower | strchr  | strrchr | strncmp     |
| memchr   | memcmp  | strnstr | atoi    | strlcpy     |
| strlcat  | calloc  | strdup  |         |             |

### Part 2 - Additional Functions

| ft_substr   | ft_strjoin | ft_strtrim | ft_split      |
| :---------- | :--------- | :--------- | :------------ |
| ft_itoa     | ft_strmapi | ft_striteri| ft_putchar_fd |
| ft_putstr_fd| ft_putendl_fd| ft_putnbr_fd|               |

### Bonus Part

| ft_lstnew      | ft_lstadd_front | ft_lstsize |
| :------------- | :-------------- | :--------- |
| ft_lstlast     | ft_lstadd_back  | ft_lstdelone |
| ft_lstclear    | ft_lstiter      | ft_lstmap  |

