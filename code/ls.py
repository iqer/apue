import os
import sys


def main():
    if len(sys.argv) != 2:
        print("usage: ls directory_name", file=sys.stderr)
        sys.exit(1)

    directory_path = sys.argv[1]

    try:
        for name in os.listdir(directory_path):
            print(name)
    except OSError as e:
        print(f"cant open {directory_path}, {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
