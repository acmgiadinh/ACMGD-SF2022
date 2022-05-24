default:
	gen

build-all:
	build-gen
	build-solve

gen:
	build-gen
	run-gen

build-gen:
	g++ source/* -Ofast -o generate

run-gen:
	./generate.exe

solve:
	build-solve
	run-solve

build-solve:
	g++ source/* -DSOLVE_INSTANCE -o solve

run-solve:
	./solve.exe

clean:
	rm -f gen* solve*