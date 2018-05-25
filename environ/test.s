
test:     file format elf64-x86-64


Disassembly of section .init:

0000000000400428 <_init>:
  400428:	48 83 ec 08          	sub    $0x8,%rsp
  40042c:	48 8b 05 c5 0b 20 00 	mov    0x200bc5(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  400433:	48 85 c0             	test   %rax,%rax
  400436:	74 05                	je     40043d <_init+0x15>
  400438:	e8 53 00 00 00       	callq  400490 <__libc_start_main@plt+0x10>
  40043d:	48 83 c4 08          	add    $0x8,%rsp
  400441:	c3                   	retq   

Disassembly of section .plt:

0000000000400450 <__stack_chk_fail@plt-0x10>:
  400450:	ff 35 b2 0b 20 00    	pushq  0x200bb2(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400456:	ff 25 b4 0b 20 00    	jmpq   *0x200bb4(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40045c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400460 <__stack_chk_fail@plt>:
  400460:	ff 25 b2 0b 20 00    	jmpq   *0x200bb2(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400466:	68 00 00 00 00       	pushq  $0x0
  40046b:	e9 e0 ff ff ff       	jmpq   400450 <_init+0x28>

0000000000400470 <printf@plt>:
  400470:	ff 25 aa 0b 20 00    	jmpq   *0x200baa(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400476:	68 01 00 00 00       	pushq  $0x1
  40047b:	e9 d0 ff ff ff       	jmpq   400450 <_init+0x28>

0000000000400480 <__libc_start_main@plt>:
  400480:	ff 25 a2 0b 20 00    	jmpq   *0x200ba2(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400486:	68 02 00 00 00       	pushq  $0x2
  40048b:	e9 c0 ff ff ff       	jmpq   400450 <_init+0x28>

Disassembly of section .plt.got:

0000000000400490 <.plt.got>:
  400490:	ff 25 62 0b 20 00    	jmpq   *0x200b62(%rip)        # 600ff8 <_DYNAMIC+0x1d0>
  400496:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000004004a0 <_start>:
  4004a0:	31 ed                	xor    %ebp,%ebp
  4004a2:	49 89 d1             	mov    %rdx,%r9
  4004a5:	5e                   	pop    %rsi
  4004a6:	48 89 e2             	mov    %rsp,%rdx
  4004a9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4004ad:	50                   	push   %rax
  4004ae:	54                   	push   %rsp
  4004af:	49 c7 c0 50 07 40 00 	mov    $0x400750,%r8
  4004b6:	48 c7 c1 e0 06 40 00 	mov    $0x4006e0,%rcx
  4004bd:	48 c7 c7 a5 06 40 00 	mov    $0x4006a5,%rdi
  4004c4:	e8 b7 ff ff ff       	callq  400480 <__libc_start_main@plt>
  4004c9:	f4                   	hlt    
  4004ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004004d0 <deregister_tm_clones>:
  4004d0:	b8 47 10 60 00       	mov    $0x601047,%eax
  4004d5:	55                   	push   %rbp
  4004d6:	48 2d 40 10 60 00    	sub    $0x601040,%rax
  4004dc:	48 83 f8 0e          	cmp    $0xe,%rax
  4004e0:	48 89 e5             	mov    %rsp,%rbp
  4004e3:	76 1b                	jbe    400500 <deregister_tm_clones+0x30>
  4004e5:	b8 00 00 00 00       	mov    $0x0,%eax
  4004ea:	48 85 c0             	test   %rax,%rax
  4004ed:	74 11                	je     400500 <deregister_tm_clones+0x30>
  4004ef:	5d                   	pop    %rbp
  4004f0:	bf 40 10 60 00       	mov    $0x601040,%edi
  4004f5:	ff e0                	jmpq   *%rax
  4004f7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4004fe:	00 00 
  400500:	5d                   	pop    %rbp
  400501:	c3                   	retq   
  400502:	0f 1f 40 00          	nopl   0x0(%rax)
  400506:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40050d:	00 00 00 

0000000000400510 <register_tm_clones>:
  400510:	be 40 10 60 00       	mov    $0x601040,%esi
  400515:	55                   	push   %rbp
  400516:	48 81 ee 40 10 60 00 	sub    $0x601040,%rsi
  40051d:	48 c1 fe 03          	sar    $0x3,%rsi
  400521:	48 89 e5             	mov    %rsp,%rbp
  400524:	48 89 f0             	mov    %rsi,%rax
  400527:	48 c1 e8 3f          	shr    $0x3f,%rax
  40052b:	48 01 c6             	add    %rax,%rsi
  40052e:	48 d1 fe             	sar    %rsi
  400531:	74 15                	je     400548 <register_tm_clones+0x38>
  400533:	b8 00 00 00 00       	mov    $0x0,%eax
  400538:	48 85 c0             	test   %rax,%rax
  40053b:	74 0b                	je     400548 <register_tm_clones+0x38>
  40053d:	5d                   	pop    %rbp
  40053e:	bf 40 10 60 00       	mov    $0x601040,%edi
  400543:	ff e0                	jmpq   *%rax
  400545:	0f 1f 00             	nopl   (%rax)
  400548:	5d                   	pop    %rbp
  400549:	c3                   	retq   
  40054a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400550 <__do_global_dtors_aux>:
  400550:	80 3d e9 0a 20 00 00 	cmpb   $0x0,0x200ae9(%rip)        # 601040 <__TMC_END__>
  400557:	75 11                	jne    40056a <__do_global_dtors_aux+0x1a>
  400559:	55                   	push   %rbp
  40055a:	48 89 e5             	mov    %rsp,%rbp
  40055d:	e8 6e ff ff ff       	callq  4004d0 <deregister_tm_clones>
  400562:	5d                   	pop    %rbp
  400563:	c6 05 d6 0a 20 00 01 	movb   $0x1,0x200ad6(%rip)        # 601040 <__TMC_END__>
  40056a:	f3 c3                	repz retq 
  40056c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400570 <frame_dummy>:
  400570:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  400575:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400579:	75 05                	jne    400580 <frame_dummy+0x10>
  40057b:	eb 93                	jmp    400510 <register_tm_clones>
  40057d:	0f 1f 00             	nopl   (%rax)
  400580:	b8 00 00 00 00       	mov    $0x0,%eax
  400585:	48 85 c0             	test   %rax,%rax
  400588:	74 f1                	je     40057b <frame_dummy+0xb>
  40058a:	55                   	push   %rbp
  40058b:	48 89 e5             	mov    %rsp,%rbp
  40058e:	ff d0                	callq  *%rax
  400590:	5d                   	pop    %rbp
  400591:	e9 7a ff ff ff       	jmpq   400510 <register_tm_clones>

0000000000400596 <f1>:
#include <stdio.h>

int f1(int val, int val2)
{
  400596:	55                   	push   %rbp
  400597:	48 89 e5             	mov    %rsp,%rbp
  40059a:	48 83 ec 30          	sub    $0x30,%rsp
  40059e:	89 7d dc             	mov    %edi,-0x24(%rbp)
  4005a1:	89 75 d8             	mov    %esi,-0x28(%rbp)
  4005a4:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4005ab:	00 00 
  4005ad:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  4005b1:	31 c0                	xor    %eax,%eax
	printf("global &val: %p\n", &val);
  4005b3:	48 8d 45 dc          	lea    -0x24(%rbp),%rax
  4005b7:	48 89 c6             	mov    %rax,%rsi
  4005ba:	bf 64 07 40 00       	mov    $0x400764,%edi
  4005bf:	b8 00 00 00 00       	mov    $0x0,%eax
  4005c4:	e8 a7 fe ff ff       	callq  400470 <printf@plt>
	printf("global &val2: %p\n", &val2);	
  4005c9:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
  4005cd:	48 89 c6             	mov    %rax,%rsi
  4005d0:	bf 75 07 40 00       	mov    $0x400775,%edi
  4005d5:	b8 00 00 00 00       	mov    $0x0,%eax
  4005da:	e8 91 fe ff ff       	callq  400470 <printf@plt>

	int num = 0;
  4005df:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)

	printf("global &num: %p\n", &num);
  4005e6:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
  4005ea:	48 89 c6             	mov    %rax,%rsi
  4005ed:	bf 87 07 40 00       	mov    $0x400787,%edi
  4005f2:	b8 00 00 00 00       	mov    $0x0,%eax
  4005f7:	e8 74 fe ff ff       	callq  400470 <printf@plt>
	
	int *ptr = &num;
  4005fc:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
  400600:	48 89 45 f0          	mov    %rax,-0x10(%rbp)

	if(val < 0) {
  400604:	8b 45 dc             	mov    -0x24(%rbp),%eax
  400607:	85 c0                	test   %eax,%eax
  400609:	79 65                	jns    400670 <f1+0xda>
		printf("input val: %d\n", val);
  40060b:	8b 45 dc             	mov    -0x24(%rbp),%eax
  40060e:	89 c6                	mov    %eax,%esi
  400610:	bf 98 07 40 00       	mov    $0x400798,%edi
  400615:	b8 00 00 00 00       	mov    $0x0,%eax
  40061a:	e8 51 fe ff ff       	callq  400470 <printf@plt>
		
		int val;
		val = 5;
  40061f:	c7 45 ec 05 00 00 00 	movl   $0x5,-0x14(%rbp)
		printf("temp &val: %p\n", &val);
  400626:	48 8d 45 ec          	lea    -0x14(%rbp),%rax
  40062a:	48 89 c6             	mov    %rax,%rsi
  40062d:	bf a7 07 40 00       	mov    $0x4007a7,%edi
  400632:	b8 00 00 00 00       	mov    $0x0,%eax
  400637:	e8 34 fe ff ff       	callq  400470 <printf@plt>
		ptr = &val;
  40063c:	48 8d 45 ec          	lea    -0x14(%rbp),%rax
  400640:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
		printf("tmp ptr: %p\n", ptr);
  400644:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  400648:	48 89 c6             	mov    %rax,%rsi
  40064b:	bf b6 07 40 00       	mov    $0x4007b6,%edi
  400650:	b8 00 00 00 00       	mov    $0x0,%eax
  400655:	e8 16 fe ff ff       	callq  400470 <printf@plt>
		printf("temp &ptr: %p\n", &ptr);
  40065a:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  40065e:	48 89 c6             	mov    %rax,%rsi
  400661:	bf c3 07 40 00       	mov    $0x4007c3,%edi
  400666:	b8 00 00 00 00       	mov    $0x0,%eax
  40066b:	e8 00 fe ff ff       	callq  400470 <printf@plt>
	}

	printf("global &ptr: %p\n", &ptr);
  400670:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  400674:	48 89 c6             	mov    %rax,%rsi
  400677:	bf d2 07 40 00       	mov    $0x4007d2,%edi
  40067c:	b8 00 00 00 00       	mov    $0x0,%eax
  400681:	e8 ea fd ff ff       	callq  400470 <printf@plt>

	return (*ptr + 1);
  400686:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  40068a:	8b 00                	mov    (%rax),%eax
  40068c:	83 c0 01             	add    $0x1,%eax
}
  40068f:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  400693:	64 48 33 14 25 28 00 	xor    %fs:0x28,%rdx
  40069a:	00 00 
  40069c:	74 05                	je     4006a3 <f1+0x10d>
  40069e:	e8 bd fd ff ff       	callq  400460 <__stack_chk_fail@plt>
  4006a3:	c9                   	leaveq 
  4006a4:	c3                   	retq   

00000000004006a5 <main>:

int main()
{
  4006a5:	55                   	push   %rbp
  4006a6:	48 89 e5             	mov    %rsp,%rbp
  4006a9:	48 83 ec 10          	sub    $0x10,%rsp
	int val = f1(-1, 1);
  4006ad:	be 01 00 00 00       	mov    $0x1,%esi
  4006b2:	bf ff ff ff ff       	mov    $0xffffffff,%edi
  4006b7:	e8 da fe ff ff       	callq  400596 <f1>
  4006bc:	89 45 fc             	mov    %eax,-0x4(%rbp)
	printf("man val: %d\n", val);
  4006bf:	8b 45 fc             	mov    -0x4(%rbp),%eax
  4006c2:	89 c6                	mov    %eax,%esi
  4006c4:	bf e3 07 40 00       	mov    $0x4007e3,%edi
  4006c9:	b8 00 00 00 00       	mov    $0x0,%eax
  4006ce:	e8 9d fd ff ff       	callq  400470 <printf@plt>
	return 0;
  4006d3:	b8 00 00 00 00       	mov    $0x0,%eax
}
  4006d8:	c9                   	leaveq 
  4006d9:	c3                   	retq   
  4006da:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004006e0 <__libc_csu_init>:
  4006e0:	41 57                	push   %r15
  4006e2:	41 56                	push   %r14
  4006e4:	41 89 ff             	mov    %edi,%r15d
  4006e7:	41 55                	push   %r13
  4006e9:	41 54                	push   %r12
  4006eb:	4c 8d 25 1e 07 20 00 	lea    0x20071e(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  4006f2:	55                   	push   %rbp
  4006f3:	48 8d 2d 1e 07 20 00 	lea    0x20071e(%rip),%rbp        # 600e18 <__init_array_end>
  4006fa:	53                   	push   %rbx
  4006fb:	49 89 f6             	mov    %rsi,%r14
  4006fe:	49 89 d5             	mov    %rdx,%r13
  400701:	4c 29 e5             	sub    %r12,%rbp
  400704:	48 83 ec 08          	sub    $0x8,%rsp
  400708:	48 c1 fd 03          	sar    $0x3,%rbp
  40070c:	e8 17 fd ff ff       	callq  400428 <_init>
  400711:	48 85 ed             	test   %rbp,%rbp
  400714:	74 20                	je     400736 <__libc_csu_init+0x56>
  400716:	31 db                	xor    %ebx,%ebx
  400718:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40071f:	00 
  400720:	4c 89 ea             	mov    %r13,%rdx
  400723:	4c 89 f6             	mov    %r14,%rsi
  400726:	44 89 ff             	mov    %r15d,%edi
  400729:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40072d:	48 83 c3 01          	add    $0x1,%rbx
  400731:	48 39 eb             	cmp    %rbp,%rbx
  400734:	75 ea                	jne    400720 <__libc_csu_init+0x40>
  400736:	48 83 c4 08          	add    $0x8,%rsp
  40073a:	5b                   	pop    %rbx
  40073b:	5d                   	pop    %rbp
  40073c:	41 5c                	pop    %r12
  40073e:	41 5d                	pop    %r13
  400740:	41 5e                	pop    %r14
  400742:	41 5f                	pop    %r15
  400744:	c3                   	retq   
  400745:	90                   	nop
  400746:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40074d:	00 00 00 

0000000000400750 <__libc_csu_fini>:
  400750:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400754 <_fini>:
  400754:	48 83 ec 08          	sub    $0x8,%rsp
  400758:	48 83 c4 08          	add    $0x8,%rsp
  40075c:	c3                   	retq   
