#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Syslog için tek yönlü bağlı liste 
struct LogNode {
    char message[256];
    struct LogNode* next;
};

// Bağlı listenin başını tutan gösterici
struct LogNode* head = NULL;

// Yeni bir log ekleme fonksiyonu
void addLog(const char* message) {
    struct LogNode* newNode = (struct LogNode*)malloc(sizeof(struct LogNode));
    if (!newNode) {
        printf("Bellek tahsisi başarısız!\n");
        return;
    }
    strcpy(newNode->message, message);
    newNode->next = head;
    head = newNode;
}

// Logları ekrana yazdırma fonksiyonu
void printLogs() {
    struct LogNode* temp = head;
    printf("\n=== Syslog Kayıtları ===\n");
    while (temp != NULL) {
        printf("%s\n", temp->message);
        temp = temp->next;
    }
    printf("========================\n");
}

// Belleği temizleme fonksiyonu
void freeLogs() {
    struct LogNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Örnek syslog verileri ekleme
    addLog("Sistem başlatıldı");
    addLog("Disk alanı yetersiz");
    addLog("Yüksek CPU kullanımı tespit edildi");

    printLogs();
    
    freeLogs(); // Belleği temizleme
    return 0;
}
