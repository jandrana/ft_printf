<p align="center"><img src=".github/printfbanner.png" alt="Printf banner"/></p>

<p align="justify">In the <code>ft_printf</code> project, I replicated the functionality of the standard printf function in C.<br><br>The main challenge of this project was to learn how variadic functions work and how to use them, which involved handling the formatting and printing of text with different data types. Completing this project made possible adding it to my <a href="https://github.com/jandrana/libft">libft</a> library for future use.</p>

- **Reminder:** ❗️ You can check all my 42 projects at <a href="https://github.com/jandrana/42-Cursus">42 Cursus</a>

<table>
  <thead>
    <th colspan="2">Code Explanation</th>
  </thead>
  <tbody>
    <tr>
      <td><a href="./ft_printf.c"><code>ft_printf</code></a></td>
      <td>Is the main function that formats and prints the given string with variadic arguments.</td>
    </tr>
    <tr>
      <td><a href="./ft_printf.c"><code>select_format</code></a></td>
      <td>A helper function used to select the format of an argument based on the provided value and then call the corresponding formatting function.</td>
    </tr>
    <tr>
      <td>Formatting<br>Functions</td>
      <td>Functions like <a href="./ft_printf_utils.c"><code>ft_pf_putchar</code></a>, <a href="./ft_printf_utils.c"><code>ft_pf_putstr</code></a>, <a href="./ft_printf_utils.c"><code>ft_pf_pointer</code></a>, and <a href="./ft_printf_utils.c"><code>ft_pf_putnbr_base</code></a> are used to format<br> and print different data types to handle various the different format specifiers</td>
    </tr>
  </tbody>
</table>

### Supported Format Specifiers
<table>
  <thead>
    <th>Format</th>
    <th>Description</th>
    <th>Formatting Function</th>
    <th>Format</th>
    <th>putnbr Base</th>
  </thead>
  <tbody>
    <tr>
      <td>%c</td>
      <td>Prints a character</td>
      <td><a href="./ft_printf_utils.c"><code>ft_pf_putchar</code></a></td>
      <td>int</td>
      <td align="center">-</td>
    </tr>
    <tr>
      <td>%s</td>
      <td>Prints a string</td>
      <td><a href="./ft_printf_utils.c"><code>ft_pf_putstr</code></a></td>
      <td>char *</td>
      <td align="center">-</td>
    </tr>
    <tr>
      <td>%p</td>
      <td>Prints a pointer</td>
      <td><a href="./ft_printf_utils.c"><code>ft_pf_pointer</code></a><br><a href="./ft_printf_utils.c"><code>ft_pf_putnbr_base</code></a></td>
      <td>unsigned long long</td>
      <td>hexadecimal</td>
    </tr>
    <tr>
      <td>%d and %i</td>
      <td>Prints signed integers</td>
      <td><a href="./ft_printf_utils.c"><code>ft_pf_putnbr_base</code></a></td>
      <td>int</td>
      <td>decimal</td>
    </tr>
    <tr>
      <td>%u</td>
      <td>Prints unsigned integers</td>
      <td><a href="./ft_printf_utils.c"><code>ft_pf_putnbr_base</code></a></td>
      <td>unsigned int</td>
      <td>decimal</td>
    </tr>
    <tr>
      <td>%x</td>
      <td>Prints integers in lowercase hexadecimal</td>
      <td><a href="./ft_printf_utils.c"><code>ft_pf_putnbr_base</code></a></td>
      <td>unsigned int</td>
      <td>hexadecimal</td>
    </tr>
    <tr>
      <td>%X</td>
      <td>Prints integers in uppercase hexadecimal</td>
      <td><a href="./ft_printf_utils.c"><code>ft_pf_putnbr_base</code></a></td>
      <td>unsigned int</td>
      <td>hexadecimal</td>
    </tr>
    <tr>
      <td>%%</td>
      <td colspan="4">Prints a percentage simbol <code>%</code></td>
    </tr>
  </tbody>
</table>

### Usage example
Main example:
```c
int  main(void)
{
    ft_printf("The answer to %s is %d.\n", "life", 42);
    ft_printf("UpTo%c", 'U');
    return (0);
}
```
Output: 
```bash
The answer to life is 42
UpToU
```
### Limitations
<p align="justify">This implementation does not include all the features and options provided by the standard printf function. It does not handle width, precision, or other formatting flags.</p>
