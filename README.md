
# Syslog Mekanizması ve Bağlı Liste ile Günlük Saklama Projesi

## 1. Syslog Mekanizması Nedir ve Ne İçin Kullanılır?

**Syslog**, Linux işletim sistemlerinde sistem günlüklerini tutan bir mekanizmadır. Sistem olaylarını, hata mesajlarını, güvenlik olaylarını ve uygulama loglarını merkezi bir yere kaydetmek için kullanılır. Genellikle günlükler `/var/log/syslog` dosyasında saklanır. Syslog, `syslogd` veya `rsyslogd` gibi daemon'lar tarafından yönetilir.

## 2. Bağlı Liste Veri Yapısını Kullanarak Syslog Günlüklerini Saklama

**Bağlı liste (Linked List)**, verileri bellekte dinamik olarak tutan bir veri yapısıdır. Bu projede, syslog verilerini bağlı liste yapısında saklayacağız. Her düğüm (node) şu bilgileri içerebilir:

- **Zaman damgası (timestamp)**
- **Log seviyesi** (INFO, ERROR, WARNING)
- **Log mesajı**
- **Sonraki düğüme işaretçi (next)**

## 3. Hangi Bağlı Liste Türü Kullanılabilir?

### a. Tek Yönlü Bağlı Liste:
- Hafif ve bellek açısından daha verimli.
- Ancak önceki kayıtlara erişmek için baştan itibaren taramak gerekir.

### b. Çift Yönlü Bağlı Liste:
- Geriye doğru erişim avantajı sağlar.
- Ancak daha fazla bellek kullanır.

### c. Döngüsel Bağlı Liste:
- Sürekli izlenen loglar için kullanılabilir.
- Ancak kodun karmaşıklığını artırır.

## 4. Proje İçin En İdeal Tercih

Bu projede, geriye dönük erişim kolaylığı sağladığı için **çift yönlü bağlı liste** kullanılması en mantıklı tercihtir.
