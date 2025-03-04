/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenkaci <fbenkaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:44:24 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/02/20 12:46:55 by fbenkaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

// int	main(void)
// {
// 	int fd = open("yo.txt", O_RDONLY | O_WRONLY);
// 	if (fd == -1)
// 	{
//         printf("non");
// 		perror("open");
// 		return (1);
// 	}
// 	close(fd);
// 	printf("hello world\n");

// 	return (0);
// }

// int main() {
//     int file = open("yo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (file == -1) {
//         perror("open");
//         return (1);
//     }

//     dup2(file, STDOUT_FILENO);  // Redirige stdout vers output.txt
//     close(file);  // On n'a plus besoin de `file`

//     printf("Ce message sera écrit dans output.txt\n");

//     return (0);
// }

// int main(void)
// {
// 	int id = fork();
// 	int n;
// 	int i;
// 	// printf("%d\n", id);
// 	if (id == 0)
// 		n = 1;
// 	else
// 	{
// 		n = 6;
// 	}
// 	if (id != 0)
// 		wait(0);
// 	for (i = n; i < n + 5; i++)
// 	{
// 		printf("%d ", i);
// 		fflush(stdout);
// 	}
// 	if (id != 0)
// 		printf("\n");

// 	return (0);
// }

// int	main(void)
// {
// 	int fd[2];
// 	int id;

// 	if (pipe(fd) == -1)
// 	{
// 		printf("An error ocurred with opening the pipe\n");
// 		return (1);
// 	}
// 	id = fork();
// 	printf("%d\n", id);
// 	if (id == 0)
// 	{
// 		int x;
// 		close(fd[0]);
// 		printf("Enter a number: ");
// 		scanf("%d", &x);
// 		write(fd[1], &x, sizeof(int));
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		int y;
// 		close(fd[1]);
// 		read(fd[0], &y, sizeof(int));
// 		close(fd[0]);
// 		printf("Got from child process %d\n", y);
// 	}

// 	return (0);
// }

// int	main(void)
// {
// 	int arr[] = {1, 2, 3, 4, 1, 2, 7};
// 	int arrSize = sizeof(arr) / sizeof(int);
// 	int start, end;
// 	int fd[2];
// 	int id;

// 	if (pipe(fd) == -1)
// 		return (1);

// 	id = fork();
// 	if (id == -1)
// 		return (2);

// 	if (id == 0)
// 	{
// 		start = 0;
// 		end = arrSize / 2;
// 	}
// 	else
// 	{
// 		start = arrSize / 2;
// 		end = arrSize;
// 	}
// 	int sum = 0;
// 	int i;
// 	for (i = start; i < end; i++)
// 		sum += arr[i];
// 	printf("calculated partial sum: %d\n", sum);

// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		write(fd[1], &sum, sizeof(sum));
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		int y;
// 		close(fd[1]);
// 		read(fd[0], &y, sizeof(y));
// 		printf("The sum is : %d\n", sum+=y);
// 		close(fd[0]);
// 		wait(0);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	int fd[2];
// 	int pid;
// 	int a = 5;

// 	if (pipe(fd) == -1)
// 		return (1);

// 	pid = fork();
// 	if (pid == -1)
// 		return (2);

// 	if (pid == 0)
// 	{
// 		int buff;
// 		if (read(fd[0], &buff, sizeof(buff)) == -1)
// 			return (3);
// 		printf("received %d\n", buff);
// 		buff *= 4;
// 		if (write(fd[1], &buff, sizeof(buff)) == -1)
// 			return (4);
// 		printf("Wrote %d\n", buff);
// 	}
// 	else
// 	{
// 		// int buff;
// 		if (write(fd[1], &a, sizeof(a)) == -1)
// 			return (5);
// 		printf("Wrote %d\n", a);
// 		wait(0); 
// 		if (read(fd[0], &a, sizeof(a)) == -1)
// 			return (6);
// 		printf("Result is %d\n", a);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);

// 	return (0);
// }

// int main(void)
// {
// 	int val;
// 	printf("HELLO\n");
//     char **args = ft_split(av[2], ' ');
// 	char *av[] = {"ls", "-l", NULL};
// 	val = execve(av[0], args, envp);
// 	if (val == -1)
// 		perror("Error");

// 	return (0);
// }

// int main(void)
// {
// 	int pid1 = fork();
// 	if (pid1 == -1)
// 	{
// 		printf("Error creating process");
// 		return (1);
// 	}
// 	if (pid1 == 0)
// 	{
// 		printf("Finished execution (%d)\n", getpid());
// 		return (0);
// 	}

// 	int pid2 = fork();
// 	if (pid2 == -1)
// 	{
// 		printf("Error creating process");
// 		return (1);
// 	}
// 	if (pid2 == 0)
// 	{
// 		printf("Finished execution (%d)\n", getpid());
// 		return (0);
// 	}
// 	int pid1_res = waitpid(pid1, NULL, 0);
// 	printf("Waited for %d\n", pid1_res);
// 	int pid2_res = waitpid(pid2, NULL, 0);
// 	printf("Waited for %d\n", pid2_res);

// 	return (0);
// }

// int main(void)
// {
		


// 	return (0);
// }