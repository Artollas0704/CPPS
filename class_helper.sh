#!/bin/bash

# C++ Class Helper - Main Menu Script
# This script provides a convenient menu for all class generation tools

show_banner() {
    echo "╔══════════════════════════════════════════════════════════════════════════════╗"
    echo "║                         C++ Class Implementation Helper                      ║"
    echo "║                              For 42 School Projects                         ║"
    echo "╚══════════════════════════════════════════════════════════════════════════════╝"
    echo ""
}

show_menu() {
    echo "Available Options:"
    echo ""
    echo "  1. Generate Basic Class          - Orthodox Canonical Form"
    echo "  2. Generate Abstract Base Class  - With pure virtual functions"
    echo "  3. Generate Derived Class        - Inherits from base class"
    echo "  4. Generate Singleton Class      - Single instance pattern"
    echo "  5. Generate Template Class       - Generic programming"
    echo "  6. Generate Interface Class      - Pure virtual interface"
    echo "  7. Run Complete Demo             - See all patterns in action"
    echo "  8. Show Class Reference Guide    - Open README.md"
    echo "  9. Quick Help                    - Show command syntax"
    echo "  0. Exit"
    echo ""
}

generate_basic() {
    echo -n "Enter class name: "
    read -r class_name
    if [ ! -z "$class_name" ]; then
        echo -n "Enter namespace (optional): "
        read -r namespace
        if [ -z "$namespace" ]; then
            ./generate_class.sh "$class_name"
        else
            ./generate_class.sh "$class_name" "$namespace"
        fi
    fi
}

generate_base() {
    echo -n "Enter abstract base class name: "
    read -r class_name
    if [ ! -z "$class_name" ]; then
        ./advanced_class_generator.sh -b "$class_name"
    fi
}

generate_derived() {
    echo -n "Enter derived class name: "
    read -r derived_name
    echo -n "Enter base class name: "
    read -r base_name
    if [ ! -z "$derived_name" ] && [ ! -z "$base_name" ]; then
        ./advanced_class_generator.sh -d "$derived_name" "$base_name"
    fi
}

generate_singleton() {
    echo -n "Enter singleton class name: "
    read -r class_name
    if [ ! -z "$class_name" ]; then
        ./advanced_class_generator.sh -s "$class_name"
    fi
}

generate_template() {
    echo -n "Enter template class name: "
    read -r class_name
    if [ ! -z "$class_name" ]; then
        ./advanced_class_generator.sh -t "$class_name"
    fi
}

generate_interface() {
    echo -n "Enter interface name (e.g., IDrawable): "
    read -r class_name
    if [ ! -z "$class_name" ]; then
        ./advanced_class_generator.sh -i "$class_name"
    fi
}

run_demo() {
    echo "Running complete demonstration..."
    ./demo_classes.sh
}

show_reference() {
    if command -v less > /dev/null 2>&1; then
        less README.md
    elif command -v more > /dev/null 2>&1; then
        more README.md
    else
        cat README.md
    fi
}

show_quick_help() {
    echo "Quick Command Reference:"
    echo ""
    echo "Basic class generation:"
    echo "  ./generate_class.sh ClassName [namespace]"
    echo ""
    echo "Advanced patterns:"
    echo "  ./advanced_class_generator.sh -b BaseClass        # Abstract base"
    echo "  ./advanced_class_generator.sh -d Child Parent     # Inheritance"  
    echo "  ./advanced_class_generator.sh -s Singleton        # Singleton pattern"
    echo "  ./advanced_class_generator.sh -t Container        # Template class"
    echo "  ./advanced_class_generator.sh -i IInterface       # Interface"
    echo ""
    echo "Demo and help:"
    echo "  ./demo_classes.sh                                 # Run full demo"
    echo "  ./class_helper.sh                                 # This menu"
    echo ""
    echo "Press any key to continue..."
    read -r
}

# Main execution
show_banner

# Check if required scripts exist
if [ ! -f "./generate_class.sh" ]; then
    echo "Error: generate_class.sh not found in current directory"
    exit 1
fi

if [ ! -f "./advanced_class_generator.sh" ]; then
    echo "Error: advanced_class_generator.sh not found in current directory"
    exit 1
fi

# Main menu loop
while true; do
    show_menu
    echo -n "Choose an option (0-9): "
    read -r choice
    echo ""

    case $choice in
        1)
            generate_basic
            ;;
        2)
            generate_base
            ;;
        3)
            generate_derived
            ;;
        4)
            generate_singleton
            ;;
        5)
            generate_template
            ;;
        6)
            generate_interface
            ;;
        7)
            run_demo
            ;;
        8)
            show_reference
            ;;
        9)
            show_quick_help
            ;;
        0)
            echo "Goodbye! Happy coding! 🚀"
            exit 0
            ;;
        *)
            echo "Invalid option. Please choose 0-9."
            ;;
    esac
    
    echo ""
    echo "Press any key to continue..."
    read -r
    echo ""
done