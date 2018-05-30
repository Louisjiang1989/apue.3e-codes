
memstr:     file format elf64-x86-64


Disassembly of section .init:

00000000004005e0 <_init>:
  4005e0:	48 83 ec 08          	sub    $0x8,%rsp
  4005e4:	48 8b 05 0d 0a 20 00 	mov    0x200a0d(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  4005eb:	48 85 c0             	test   %rax,%rax
  4005ee:	74 05                	je     4005f5 <_init+0x15>
  4005f0:	e8 bb 00 00 00       	callq  4006b0 <strerror@plt+0x10>
  4005f5:	48 83 c4 08          	add    $0x8,%rsp
  4005f9:	c3                   	retq   

Disassembly of section .plt:

0000000000400600 <__errno_location@plt-0x10>:
  400600:	ff 35 02 0a 20 00    	pushq  0x200a02(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400606:	ff 25 04 0a 20 00    	jmpq   *0x200a04(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40060c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400610 <__errno_location@plt>:
  400610:	ff 25 02 0a 20 00    	jmpq   *0x200a02(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400616:	68 00 00 00 00       	pushq  $0x0
  40061b:	e9 e0 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400620 <fmemopen@plt>:
  400620:	ff 25 fa 09 20 00    	jmpq   *0x2009fa(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400626:	68 01 00 00 00       	pushq  $0x1
  40062b:	e9 d0 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400630 <__stack_chk_fail@plt>:
  400630:	ff 25 f2 09 20 00    	jmpq   *0x2009f2(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400636:	68 02 00 00 00       	pushq  $0x2
  40063b:	e9 c0 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400640 <printf@plt>:
  400640:	ff 25 ea 09 20 00    	jmpq   *0x2009ea(%rip)        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400646:	68 03 00 00 00       	pushq  $0x3
  40064b:	e9 b0 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400650 <memset@plt>:
  400650:	ff 25 e2 09 20 00    	jmpq   *0x2009e2(%rip)        # 601038 <_GLOBAL_OFFSET_TABLE_+0x38>
  400656:	68 04 00 00 00       	pushq  $0x4
  40065b:	e9 a0 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400660 <__libc_start_main@plt>:
  400660:	ff 25 da 09 20 00    	jmpq   *0x2009da(%rip)        # 601040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400666:	68 05 00 00 00       	pushq  $0x5
  40066b:	e9 90 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400670 <fflush@plt>:
  400670:	ff 25 d2 09 20 00    	jmpq   *0x2009d2(%rip)        # 601048 <_GLOBAL_OFFSET_TABLE_+0x48>
  400676:	68 06 00 00 00       	pushq  $0x6
  40067b:	e9 80 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400680 <exit@plt>:
  400680:	ff 25 ca 09 20 00    	jmpq   *0x2009ca(%rip)        # 601050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400686:	68 07 00 00 00       	pushq  $0x7
  40068b:	e9 70 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400690 <fwrite@plt>:
  400690:	ff 25 c2 09 20 00    	jmpq   *0x2009c2(%rip)        # 601058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400696:	68 08 00 00 00       	pushq  $0x8
  40069b:	e9 60 ff ff ff       	jmpq   400600 <_init+0x20>

00000000004006a0 <strerror@plt>:
  4006a0:	ff 25 ba 09 20 00    	jmpq   *0x2009ba(%rip)        # 601060 <_GLOBAL_OFFSET_TABLE_+0x60>
  4006a6:	68 09 00 00 00       	pushq  $0x9
  4006ab:	e9 50 ff ff ff       	jmpq   400600 <_init+0x20>

Disassembly of section .plt.got:

00000000004006b0 <.plt.got>:
  4006b0:	ff 25 42 09 20 00    	jmpq   *0x200942(%rip)        # 600ff8 <_DYNAMIC+0x1d0>
  4006b6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000004006c0 <_start>:
  4006c0:	31 ed                	xor    %ebp,%ebp
  4006c2:	49 89 d1             	mov    %rdx,%r9
  4006c5:	5e                   	pop    %rsi
  4006c6:	48 89 e2             	mov    %rsp,%rdx
  4006c9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4006cd:	50                   	push   %rax
  4006ce:	54                   	push   %rsp
  4006cf:	49 c7 c0 40 09 40 00 	mov    $0x400940,%r8
  4006d6:	48 c7 c1 d0 08 40 00 	mov    $0x4008d0,%rcx
  4006dd:	48 c7 c7 b6 07 40 00 	mov    $0x4007b6,%rdi
  4006e4:	e8 77 ff ff ff       	callq  400660 <__libc_start_main@plt>
  4006e9:	f4                   	hlt    
  4006ea:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004006f0 <deregister_tm_clones>:
  4006f0:	b8 7f 10 60 00       	mov    $0x60107f,%eax
  4006f5:	55                   	push   %rbp
  4006f6:	48 2d 78 10 60 00    	sub    $0x601078,%rax
  4006fc:	48 83 f8 0e          	cmp    $0xe,%rax
  400700:	48 89 e5             	mov    %rsp,%rbp
  400703:	76 1b                	jbe    400720 <deregister_tm_clones+0x30>
  400705:	b8 00 00 00 00       	mov    $0x0,%eax
  40070a:	48 85 c0             	test   %rax,%rax
  40070d:	74 11                	je     400720 <deregister_tm_clones+0x30>
  40070f:	5d                   	pop    %rbp
  400710:	bf 78 10 60 00       	mov    $0x601078,%edi
  400715:	ff e0                	jmpq   *%rax
  400717:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40071e:	00 00 
  400720:	5d                   	pop    %rbp
  400721:	c3                   	retq   
  400722:	0f 1f 40 00          	nopl   0x0(%rax)
  400726:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40072d:	00 00 00 

0000000000400730 <register_tm_clones>:
  400730:	be 78 10 60 00       	mov    $0x601078,%esi
  400735:	55                   	push   %rbp
  400736:	48 81 ee 78 10 60 00 	sub    $0x601078,%rsi
  40073d:	48 c1 fe 03          	sar    $0x3,%rsi
  400741:	48 89 e5             	mov    %rsp,%rbp
  400744:	48 89 f0             	mov    %rsi,%rax
  400747:	48 c1 e8 3f          	shr    $0x3f,%rax
  40074b:	48 01 c6             	add    %rax,%rsi
  40074e:	48 d1 fe             	sar    %rsi
  400751:	74 15                	je     400768 <register_tm_clones+0x38>
  400753:	b8 00 00 00 00       	mov    $0x0,%eax
  400758:	48 85 c0             	test   %rax,%rax
  40075b:	74 0b                	je     400768 <register_tm_clones+0x38>
  40075d:	5d                   	pop    %rbp
  40075e:	bf 78 10 60 00       	mov    $0x601078,%edi
  400763:	ff e0                	jmpq   *%rax
  400765:	0f 1f 00             	nopl   (%rax)
  400768:	5d                   	pop    %rbp
  400769:	c3                   	retq   
  40076a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400770 <__do_global_dtors_aux>:
  400770:	80 3d 01 09 20 00 00 	cmpb   $0x0,0x200901(%rip)        # 601078 <__TMC_END__>
  400777:	75 11                	jne    40078a <__do_global_dtors_aux+0x1a>
  400779:	55                   	push   %rbp
  40077a:	48 89 e5             	mov    %rsp,%rbp
  40077d:	e8 6e ff ff ff       	callq  4006f0 <deregister_tm_clones>
  400782:	5d                   	pop    %rbp
  400783:	c6 05 ee 08 20 00 01 	movb   $0x1,0x2008ee(%rip)        # 601078 <__TMC_END__>
  40078a:	f3 c3                	repz retq 
  40078c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400790 <frame_dummy>:
  400790:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  400795:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400799:	75 05                	jne    4007a0 <frame_dummy+0x10>
  40079b:	eb 93                	jmp    400730 <register_tm_clones>
  40079d:	0f 1f 00             	nopl   (%rax)
  4007a0:	b8 00 00 00 00       	mov    $0x0,%eax
  4007a5:	48 85 c0             	test   %rax,%rax
  4007a8:	74 f1                	je     40079b <frame_dummy+0xb>
  4007aa:	55                   	push   %rbp
  4007ab:	48 89 e5             	mov    %rsp,%rbp
  4007ae:	ff d0                	callq  *%rax
  4007b0:	5d                   	pop    %rbp
  4007b1:	e9 7a ff ff ff       	jmpq   400730 <register_tm_clones>

00000000004007b6 <main>:
#include <string.h>

#define BSZ 48

int main()
{
  4007b6:	55                   	push   %rbp
  4007b7:	48 89 e5             	mov    %rsp,%rbp
  4007ba:	48 83 ec 50          	sub    $0x50,%rsp
  4007be:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4007c5:	00 00 
  4007c7:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  4007cb:	31 c0                	xor    %eax,%eax
	FILE *fp;
	char buf[BSZ];
	
	memset(buf, 'a', BSZ-2);
  4007cd:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  4007d1:	ba 2e 00 00 00       	mov    $0x2e,%edx
  4007d6:	be 61 00 00 00       	mov    $0x61,%esi
  4007db:	48 89 c7             	mov    %rax,%rdi
  4007de:	e8 6d fe ff ff       	callq  400650 <memset@plt>
	buf[BSZ-2] = '\0';
  4007e3:	c6 45 ee 00          	movb   $0x0,-0x12(%rbp)
	buf[BSZ-1] = 'X';
  4007e7:	c6 45 ef 58          	movb   $0x58,-0x11(%rbp)

	printf("before fmemopen buf: %s\n", buf);
  4007eb:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  4007ef:	48 89 c6             	mov    %rax,%rsi
  4007f2:	bf 58 09 40 00       	mov    $0x400958,%edi
  4007f7:	b8 00 00 00 00       	mov    $0x0,%eax
  4007fc:	e8 3f fe ff ff       	callq  400640 <printf@plt>
	printf("BSZ: %d\n", BSZ);
  400801:	be 30 00 00 00       	mov    $0x30,%esi
  400806:	bf 71 09 40 00       	mov    $0x400971,%edi
  40080b:	b8 00 00 00 00       	mov    $0x0,%eax
  400810:	e8 2b fe ff ff       	callq  400640 <printf@plt>

	if ((fp = fmemopen(buf, BSZ, "w+")) == NULL) {
  400815:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  400819:	ba 7a 09 40 00       	mov    $0x40097a,%edx
  40081e:	be 30 00 00 00       	mov    $0x30,%esi
  400823:	48 89 c7             	mov    %rax,%rdi
  400826:	e8 f5 fd ff ff       	callq  400620 <fmemopen@plt>
  40082b:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
  40082f:	48 83 7d b8 00       	cmpq   $0x0,-0x48(%rbp)
  400834:	75 2a                	jne    400860 <main+0xaa>
		printf("fmemopen error %s\n", strerror(errno));
  400836:	e8 d5 fd ff ff       	callq  400610 <__errno_location@plt>
  40083b:	8b 00                	mov    (%rax),%eax
  40083d:	89 c7                	mov    %eax,%edi
  40083f:	e8 5c fe ff ff       	callq  4006a0 <strerror@plt>
  400844:	48 89 c6             	mov    %rax,%rsi
  400847:	bf 7d 09 40 00       	mov    $0x40097d,%edi
  40084c:	b8 00 00 00 00       	mov    $0x0,%eax
  400851:	e8 ea fd ff ff       	callq  400640 <printf@plt>
		exit(-1);
  400856:	bf ff ff ff ff       	mov    $0xffffffff,%edi
  40085b:	e8 20 fe ff ff       	callq  400680 <exit@plt>
	}
	
	printf("fp: %p\n", fp);
  400860:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  400864:	48 89 c6             	mov    %rax,%rsi
  400867:	bf 90 09 40 00       	mov    $0x400990,%edi
  40086c:	b8 00 00 00 00       	mov    $0x0,%eax
  400871:	e8 ca fd ff ff       	callq  400640 <printf@plt>
	fprintf(fp, "hello, world cccccccccccccccccc");
  400876:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  40087a:	48 89 c1             	mov    %rax,%rcx
  40087d:	ba 1f 00 00 00       	mov    $0x1f,%edx
  400882:	be 01 00 00 00       	mov    $0x1,%esi
  400887:	bf 98 09 40 00       	mov    $0x400998,%edi
  40088c:	e8 ff fd ff ff       	callq  400690 <fwrite@plt>
	
	fflush(fp);
  400891:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  400895:	48 89 c7             	mov    %rax,%rdi
  400898:	e8 d3 fd ff ff       	callq  400670 <fflush@plt>
	
	printf("after fmemopen buf: %s\n", buf);
  40089d:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  4008a1:	48 89 c6             	mov    %rax,%rsi
  4008a4:	bf b8 09 40 00       	mov    $0x4009b8,%edi
  4008a9:	b8 00 00 00 00       	mov    $0x0,%eax
  4008ae:	e8 8d fd ff ff       	callq  400640 <printf@plt>

	return (0);
  4008b3:	b8 00 00 00 00       	mov    $0x0,%eax
}
  4008b8:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  4008bc:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  4008c3:	00 00 
  4008c5:	74 05                	je     4008cc <main+0x116>
  4008c7:	e8 64 fd ff ff       	callq  400630 <__stack_chk_fail@plt>
  4008cc:	c9                   	leaveq 
  4008cd:	c3                   	retq   
  4008ce:	66 90                	xchg   %ax,%ax

00000000004008d0 <__libc_csu_init>:
  4008d0:	41 57                	push   %r15
  4008d2:	41 56                	push   %r14
  4008d4:	41 89 ff             	mov    %edi,%r15d
  4008d7:	41 55                	push   %r13
  4008d9:	41 54                	push   %r12
  4008db:	4c 8d 25 2e 05 20 00 	lea    0x20052e(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  4008e2:	55                   	push   %rbp
  4008e3:	48 8d 2d 2e 05 20 00 	lea    0x20052e(%rip),%rbp        # 600e18 <__init_array_end>
  4008ea:	53                   	push   %rbx
  4008eb:	49 89 f6             	mov    %rsi,%r14
  4008ee:	49 89 d5             	mov    %rdx,%r13
  4008f1:	4c 29 e5             	sub    %r12,%rbp
  4008f4:	48 83 ec 08          	sub    $0x8,%rsp
  4008f8:	48 c1 fd 03          	sar    $0x3,%rbp
  4008fc:	e8 df fc ff ff       	callq  4005e0 <_init>
  400901:	48 85 ed             	test   %rbp,%rbp
  400904:	74 20                	je     400926 <__libc_csu_init+0x56>
  400906:	31 db                	xor    %ebx,%ebx
  400908:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40090f:	00 
  400910:	4c 89 ea             	mov    %r13,%rdx
  400913:	4c 89 f6             	mov    %r14,%rsi
  400916:	44 89 ff             	mov    %r15d,%edi
  400919:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40091d:	48 83 c3 01          	add    $0x1,%rbx
  400921:	48 39 eb             	cmp    %rbp,%rbx
  400924:	75 ea                	jne    400910 <__libc_csu_init+0x40>
  400926:	48 83 c4 08          	add    $0x8,%rsp
  40092a:	5b                   	pop    %rbx
  40092b:	5d                   	pop    %rbp
  40092c:	41 5c                	pop    %r12
  40092e:	41 5d                	pop    %r13
  400930:	41 5e                	pop    %r14
  400932:	41 5f                	pop    %r15
  400934:	c3                   	retq   
  400935:	90                   	nop
  400936:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40093d:	00 00 00 

0000000000400940 <__libc_csu_fini>:
  400940:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400944 <_fini>:
  400944:	48 83 ec 08          	sub    $0x8,%rsp
  400948:	48 83 c4 08          	add    $0x8,%rsp
  40094c:	c3                   	retq   
