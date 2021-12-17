FROM gcc
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN  g++ -std=c++17  main.cpp expense.cpp fixedexpense.cpp discretionaryexpense.cpp manager.cpp  -o main
CMD ["./main"]
