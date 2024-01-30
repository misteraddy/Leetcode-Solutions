/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    const stack = [];

    // Helper function to check if a string is an integer
    const isInteger = (s) => /^\d+$/.test(s);

    for (const token of tokens) {
        switch (token) {
            case '+':
                stack.push(stack.pop() + stack.pop());
                break;
            case '-':
                stack.push(-stack.pop() + stack.pop());
                break;
            case '*':
                stack.push(stack.pop() * stack.pop());
                break;
            case '/':
                const divisor = stack.pop();
                const dividend = stack.pop();
                stack.push((dividend / divisor) | 0); // Truncate towards zero
                break;
            default:
                // Use unary plus operator to convert string to number
                stack.push(+token);
                break;
        }
    }

    return stack[0];
};