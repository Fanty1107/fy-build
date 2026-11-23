## Cbuild

### Details
- Is a simple and small build system for C++

- It expected a file.build in the root dir of your project

- Only works on linux because of unistd header

- See the example .build in struct.build in the repo

- Do not expected a arg for running you only need .build and the binary

- Detects all cpp and cc files in your specified dir and includes

- It is not intend to replace cmake or makefiles just a little side proj, but you can modify and make better :)

### Build
- Make sure to have build essentials in your distro(c++ compiler and make)
```bash
    git clone https://github.com/Fanty1107/fy-build.git

    make release
```
