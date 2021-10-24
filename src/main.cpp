#include <fstream>
#include <vector>

#include "shape.h"

void selection_sort_by_perimiter(std::vector<Shape*>* shapes) {
    for (int i = 0; i < shapes->size(); i++) {
        Shape** smallest = &shapes->at(i);
        double perimiter = (*smallest)->perimeter();
        for (int j = i + 1; j < shapes->size(); j++) {
            Shape** other = &shapes->at(j);
            double p = (*other)->perimeter();
            if (p < perimiter) {
                smallest = other;
                perimiter = p;
            }
        }

        Shape* a = *smallest;
        Shape* b = shapes->at(i);
        shapes->at(i) = a;
        *smallest = b;
    }
}

struct Options {
    Buffer* input = nullptr;
    std::ostream* output = nullptr;
    std::ifstream in_file;
    std::ofstream out_file;

    static Options parse_args(int argc, char** argv) {
        Options result = {nullptr, &std::cout};
        result.input = new Stream(std::cin);

        if (argc <= 1) {
            dprintf(1,
                    "Finish input with EOF (Ctrl+D). Run with -h for help\n");
            return result;
        }

        ++argv;
        while (*argv != 0) {
            char* option = *argv;
            // Ensure that option looks like '-', symbol, '\0'
            if (!(option[0] == '-' && option[1] != '\0' && option[2] == '\0')) {
                std::cerr << "Invalid option: " << option << std::endl;
                exit(1);
            }
            ++argv;

            if (option[1] == 'h') {
                std::cerr << "Usage:\n";
                std::cerr << "  default: read from Stream, write to stdout.\n";
                std::cerr << "  -r <seed> to use random values\n";
                std::cerr << "  -f <filename> to read from file\n";
                std::cerr << "  -o <filename> to set output file\n";
                std::cerr << "Input format:\n";
                std::cerr << "  First line contains number of shapes.\n";
                std::cerr << "  In the following lines shapes are entered.\n";
                std::cerr << "  All values are separated using whitespace\n";
                std::cerr << "Shapes:\n";
                std::cerr << "  Circle:    `1 <color> <x> <y> <radius>`\n";
                std::cerr << "  Rectangle: `2 <color> <x1> <y1> <x2> <y2>`\n";
                std::cerr
                    << "             where (x1, y1) is the left-upper corner\n";
                std::cerr << "             and (x2, y2) is the bottom-left.\n";
                std::cerr << "  Triangle:  `3 <color> <x1> <y1> <x2> <y2> <x3> "
                             "<y3>`\n";
                std::cerr << "Colors:\n";
                for (int i = Color::Value::RED; i < Color::Value::MAX_COLOR;
                     i++) {
                    std::cerr << "  " << i << ". ";
                    auto val = static_cast<Color::Value>(i);
                    Color(val).print(std::cerr);
                    std::cerr << "\n";
                }
                exit(0);
            }

            char* argument = *argv;
            if (argv == NULL) {
                dprintf(2, "Expected argument after %s", option);
                exit(1);
            }
            ++argv;

            switch (option[1]) {
                case 'r': {
                    // Randomized
                    int seed = atoi(argument);
                    srand(seed);
                    result.input = new Randomized();
                    break;
                }
                case 'f': {
                    // Read from file
                    result.in_file.open(argument);
                    result.input = new Stream(result.in_file);
                    break;
                }
                case 'o': {
                    // Output to file
                    result.out_file.open(argument);
                    result.output = &result.out_file;
                    break;
                }
                default: {
                    std::cerr << "Unknown option: " << option;
                    exit(1);
                }
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Options opts = Options::parse_args(argc, argv);

    unsigned int count = opts.input->read_uint(1, 30);
    std::vector<Shape*> shapes;
    for (int i = 0; i < count; ++i) {
        Shape* shape = Shape::read(*opts.input);
        shapes.push_back(shape);
    }

    *opts.output << "Count: " << shapes.size() << std::endl;

    *opts.output << "Data:\n";
    for (size_t i = 0; i < shapes.size(); ++i) {
        *opts.output << (i+1) << ". ";
        shapes[i]->print(*opts.output);
        *opts.output << "\n";
    }

    selection_sort_by_perimiter(&shapes);

    *opts.output << "Sorted:\n";
    for (size_t i = 0; i < shapes.size(); ++i) {
        *opts.output << (i + 1) << ". ";
        shapes[i]->print(*opts.output);
        *opts.output << "\n";
    }
}
