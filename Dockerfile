FROM gcc:latest

WORKDIR /app

COPY . .

RUN g++ 8_Queens_Problem.cpp -o 8queens

CMD ["./8queens"]
