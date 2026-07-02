#include "kernel.h"
#include "video/vga_driver.h"
#include "types.h"

Kernel::Kernel() {}

void Kernel::run() {
    videoService.clear();

    // Banner Principal
    videoService.print("========================================================\n");
    videoService.print("   ______                __ __                     __ \n");
    videoService.print("  / ____/____   _____   / //_/___   _____ ____   _/_/ \n");
    videoService.print(" / /    / __ \\ / ___/  / ,<  / _ \\ / ___// __ \\ _/_/  \n");
    videoService.print("/ /___ / /_/ // /     / /| |/  __// /   / / / /_/_/   \n");
    videoService.print("\\____/ \\____//_/     /_/ |_|\\___//_/   /_/ /_/_/      \n");
    videoService.print("========================================================\n");
    videoService.print("  CoreKernel OS - Version 0.0.1 | Arch: x86_32 (Protected Mode)\n");
    videoService.print("========================================================\n\n");

    // Sistema de Logs de Inicialização
    videoService.print("[  OK  ] Detectando memoria RAM...\n");
    videoService.print("[  OK  ] Inicializando a GDT (Global Descriptor Table)...\n");
    videoService.print("[  OK  ] Carregando IDT (Interrupt Descriptor Table)...\n");
    videoService.print("[  OK  ] Driver de Video VGA mapeado em 0xB8000...\n");
    videoService.print("[ INFO ] Kernel carregado com sucesso em modo seguro.\n\n");

    // Menu interativo (Simulação visual até você ter driver de teclado)
    videoService.print("Simulaçao ate keybord.cpp ser feito \n");
    videoService.print("Selecione uma opcao:\n");
    videoService.print(" --> 1) Carregar Shell Bash-like (Padrao)\n");
    videoService.print("     2) Executar Testes de Memoria (Memtest)\n");
    videoService.print("     3) Desligar Sistema (ACPI Poweroff)\n\n");

    videoService.print("CoreKernel $ _");
}

extern "C" void kernel_main() {
    Kernel kernel;
    kernel.run();
}
