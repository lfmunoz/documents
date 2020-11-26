

.PHONY: default docs

default:
	rustc --version
	cargo --version

docs:
	rustup docs



build: main.rs
	rustc main.rs

run: build
	./main